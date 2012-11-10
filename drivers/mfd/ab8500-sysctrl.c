/*
 * Copyright (C) ST-Ericsson SA 2010
 * Author: Mattias Nilsson <mattias.i.nilsson@stericsson.com> for ST Ericsson.
 * License terms: GNU General Public License (GPL) version 2
 */

#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/pm.h>
#include <linux/signal.h>
#include <linux/reboot.h>
#include <linux/mfd/ab8500.h>
#include <linux/mfd/abx500.h>
#include <linux/mfd/ab8500/ab8500-bm.h>
#include <linux/mfd/ab8500/sysctrl.h>

static struct device *sysctrl_dev;
extern bool vbus_state;

void ab8500_power_off(void)
{
	sigset_t old;
	sigset_t all;
	u8 data;

	abx500_get_register_interruptible(sysctrl_dev, AB8500_CHARGER,
					  AB8500_CH_STATUS1_REG, &data);

	if (vbus_state || data & 0x1) {
		pr_info("%s : Reboot when charger is connected\n", __func__);
		machine_restart("ta"); /* actually it can be any other charger */
		while(1);
	}

	sigfillset(&all);

	if (!sigprocmask(SIG_BLOCK, &all, &old)) {
		(void)ab8500_sysctrl_set(AB8500_STW4500CTRL1,
					 AB8500_STW4500CTRL1_SWOFF |
					 AB8500_STW4500CTRL1_SWRESET4500N);
		(void)sigprocmask(SIG_SETMASK, &old, NULL);
	}
}

static inline bool valid_bank(u8 bank)
{
	return ((bank == AB8500_SYS_CTRL1_BLOCK) ||
		(bank == AB8500_SYS_CTRL2_BLOCK));
}

int ab8500_sysctrl_read(u16 reg, u8 *value)
{
	u8 bank;

	if (sysctrl_dev == NULL)
		return -EAGAIN;

	bank = (reg >> 8);
	if (!valid_bank(bank))
		return -EINVAL;

	return abx500_get_register_interruptible(sysctrl_dev, bank,
		(u8)(reg & 0xFF), value);
}

int ab8500_sysctrl_write(u16 reg, u8 mask, u8 value)
{
	u8 bank;

	if (sysctrl_dev == NULL)
		return -EAGAIN;

	bank = (reg >> 8);
	if (!valid_bank(bank))
		return -EINVAL;

	return abx500_mask_and_set_register_interruptible(sysctrl_dev, bank,
		(u8)(reg & 0xFF), mask, value);
}

static int __devinit ab8500_sysctrl_probe(struct platform_device *pdev)
{
	struct ab8500_platform_data *plat;

	sysctrl_dev = &pdev->dev;
	plat = dev_get_platdata(pdev->dev.parent);
	if (plat->pm_power_off)
		pm_power_off = ab8500_power_off;
	return 0;
}

static int __devexit ab8500_sysctrl_remove(struct platform_device *pdev)
{
	sysctrl_dev = NULL;
	return 0;
}

static struct platform_driver ab8500_sysctrl_driver = {
	.driver = {
		.name = "ab8500-sysctrl",
		.owner = THIS_MODULE,
	},
	.probe = ab8500_sysctrl_probe,
	.remove = __devexit_p(ab8500_sysctrl_remove),
};

static int __init ab8500_sysctrl_init(void)
{
	return platform_driver_register(&ab8500_sysctrl_driver);
}
subsys_initcall(ab8500_sysctrl_init);

MODULE_AUTHOR("Mattias Nilsson <mattias.i.nilsson@stericsson.com");
MODULE_DESCRIPTION("AB8500 system control driver");
MODULE_LICENSE("GPL v2");
