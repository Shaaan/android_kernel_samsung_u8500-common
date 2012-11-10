/*
*  Atmel maXTouch header file
*
*  Copyright (c) 2010 Iiro Valkonen <iiro.valkonen@atmel.com>
*  Copyright (c) 2010 Ulf Samuelsson <ulf.samuelsson@atmel.com>
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License version 2 or 3 as
*  published by the Free Software Foundation.
*  See the file "COPYING" in the main directory of this archive
*  for more details.
*
*/
#include <linux/earlysuspend.h>
#include <linux/wakelock.h>

#define MXT_I2C_APP_ADDR        0x4A
#define MXT_I2C_BOOTLOADER_ADDR 0x24

#define MXT_I2C_SPEED_KHZ  400
#define MXT_I2C_MAX_LENGTH 300   /* TO_CHK: Is this a correct value? */

#define MAXTOUCH_FAMILYID                               0x81/*0x80*/
#define MXT224_CAL_VARIANTID                            0x01
#define MXT224_UNCAL_VARIANTID                          0x00

#define MXT_MAX_X_VAL_12_BIT                            4095
#define MXT_MAX_Y_VAL_12_BIT                            4095
#define MXT_MAX_X_VAL_10_BIT                            1023
#define MXT_MAX_Y_VAL_10_BIT                            1023


#define MXT_MAX_REPORTED_WIDTH                          255
#define MXT_MAX_REPORTED_PRESSURE                       255


#define MXT_MAX_TOUCH_SIZE                              255
#define MXT_MAX_NUM_TOUCHES                             10  /* 10 finger */

/* Fixed addresses inside maXTouch device */
#define MXT_ADDR_INFO_BLOCK                             0
#define MXT_ADDR_OBJECT_TABLE                           7
#define MXT_ID_BLOCK_SIZE                               7
#define MXT_OBJECT_TABLE_ELEMENT_SIZE                   6
/* Object types */
#define MXT_GEN_MESSAGEPROCESSOR_T5                     5u
#define MXT_GEN_COMMANDPROCESSOR_T6                     6u
#define MXT_GEN_POWERCONFIG_T7                          7u
#define MXT_GEN_ACQUIRECONFIG_T8                        8u
#define MXT_TOUCH_MULTITOUCHSCREEN_T9                   9u
#define MXT_TOUCH_KEYARRAY_T15                          15u
#define MXT_SPT_COMMSCONFIG_T18                         18u
#define MXT_SPT_GPIOPWM_T19                             19u
#define MXT_TOUCH_PROXIMITY_T23                         23u
#define MXT_PROCI_ONETOUCHGESTUREPROCESSOR_T24          24u
#define MXT_SPT_SELFTEST_T25                            25u
#define MXT_DEBUG_DIAGNOSTICS_T37                       37u
#define MXT_USER_INFO_T38                               38u

#define MXT_SPT_COMMSCONFIG_T18                         18u
#define MXT_PROCI_GRIPSUPPRESSION_T40                   40u  /* added MXT224E */
#define MXT_PROCI_TOUCHSUPPRESSION_T42                  42u  /* added MXT224E */
#define MXT_SPT_CTECONFIG_T46                           46u  /* added MXT224E */
#define MXT_PROCI_STYLUS_T47                            47u  /* added MXT224E */
#define MXT_PROCG_NOISESUPPRESSION_T48                  48u  /* added MXT224E */
#define MXT_GEN_INFOBLOCK16BIT_T254                     254u  /*added MXT224E */
#define	MXT_MAX_OBJECT_TYPES				50u	/* temporary */


#define MXT_END_OF_MESSAGES                             255u

/* Configuration Object Adress Fields */
/* GEN_MESSAGEPROCESSOR_T5  Address Definitions         */
/* T5 does not have any configuration */

/* GEN_COMMANDPROCESSOR_T6  Address Definitions         */
#define MXT_ADR_T6_RESET                                0x00
#define MXT_ADR_T6_BACKUPNV                             0x01
#define MXT_ADR_T6_CALIBRATE                            0x02
#define MXT_ADR_T6_REPORTALL                            0x03
#define MXT_ADR_T6_RESERVED                             0x04
#define MXT_ADR_T6_DIAGNOSTICS                          0x05
/* T6 Diagnostics Debug Command */
#define MXT_CMD_T6_PAGE_UP                              0x01
#define MXT_CMD_T6_PAGE_DOWN                            0x02
#define MXT_CMD_T6_DELTAS_MODE                          0x10
#define MXT_CMD_T6_REFERENCES_MODE                      0x11
#define MXT_CMD_T6_CTE_MODE                             0x31

/* GEN_POWERCONFIG_T7 Address Definitions               */
#define MXT_ADR_T7_IDLEACQINT                           0x00
#define MXT_ADR_T7_ACTVACQINT                           0x01
#define MXT_ADR_T7_ACTV2IDLETO                          0x02

/* GEN_ACQUIRECONFIG_T8 Address Definitions             */
#define MXT_ADR_T8_CHRGTIME                             0x00
#define MXT_ADR_T8_RESERVED                             0x01
#define MXT_ADR_T8_TCHDRIFT                             0x02
#define MXT_ADR_T8_DRIFTSTS                             0x03
#define MXT_ADR_T8_TCHAUTOCAL                           0x04
#define MXT_ADR_T8_SYNC                                 0x05
#define MXT_ADR_T8_ATCHCALST                            0x06
#define MXT_ADR_T8_ATCHCALSTHR                          0x07
#define MXT_ADR_T8_ATCHFRCCALTHR                        0x08         /* V2.0 added */
#define MXT_ADR_T8_ATCHFRCCALRATIO                      0x09         /* V2.0 added */

/* TOUCH_MULTITOUCHSCREEN_T9 Address Definitions        */
#define MXT_ADR_T9_CTRL                                 0x00
#define MXT_T9_CFGB_ENABLE(x)                           (((x) >> 0) & 0x01)
#define MXT_T9_CFGB_RPRTEN(x)                           (((x) >> 1) & 0x01)
#define MXT_T9_CFGB_DISAMP(x)                           (((x) >> 2) & 0x01)
#define MXT_T9_CFGB_DISVECT(x)                          (((x) >> 3) & 0x01)
#define MXT_T9_CFGB_DISMOVE(x)                          (((x) >> 4) & 0x01)
#define MXT_T9_CFGB_DISREL(x)                           (((x) >> 5) & 0x01)
#define MXT_T9_CFGB_DISPRSS(x)                          (((x) >> 6) & 0x01)
#define MXT_T9_CFGB_SCANEN(x)                           (((x) >> 7) & 0x01)


#define MXT_T9_ENABLE                                   (0x01)
#define MXT_T9_RPRTEN                                   (0x02)
#define MXT_T9_DISAMP                                   (0x04)
#define MXT_T9_DISVECT                                  (0x08)
#define MXT_T9_DISMOVE                                  (0x10)
#define MXT_T9_DISREL                                   (0x20)
#define MXT_T9_DISPRSS                                  (0x40)
#define MXT_T9_SCANEN                                   (0x80)

#define MXT_ADR_T9_XORIGIN                              0x01
#define MXT_ADR_T9_YORIGIN                              0x02
#define MXT_ADR_T9_XSIZE                                0x03
#define MXT_ADR_T9_YSIZE                                0x04
#define MXT_ADR_T9_AKSCFG                               0x05
#define MXT_ADR_T9_BLEN                                 0x06
#define MXT_T9_CFGBF_BL(x)                              (x & 0x0F)
#define MXT_T9_CFGBF_GAIN(x)                            ((x >> 4) & 0x0F)
#define MXT_ADR_T9_TCHTHR                               0x07
#define MXT_ADR_T9_TCHDI                                0x08
#define MXT_ADR_T9_ORIENT                               0x09
#define MXT_T9_CFGB_SWITCH(x)                           (((x) >> 0) & 0x01)
#define MXT_T9_CFGB_INVERTX(x)                          (((x) >> 1) & 0x01)
#define MXT_T9_CFGB_INVERTY(x)                          (((x) >> 2) & 0x01)
#define MXT_ADR_T9_MRGTIMEOUT                           0x0a
#define MXT_ADR_T9_MOVHYSTI                             0x0b
#define MXT_ADR_T9_MOVHYSTN                             0x0c
#define MXT_ADR_T9_MOVFILTER                            0x0d
#define MXT_T9_CFGBF_ADAPTTHR(x)                        (((x) >> 0) & 0xF)
#define MXT_T9_CFGB_DISABLE(x)                          (((x) >> 7) & 0x01)
#define MXT_ADR_T9_NUMTOUCH                             0x0e
#define MXT_ADR_T9_MRGHYST                              0x0f
#define MXT_ADR_T9_MRGTHR                               0x10
#define MXT_ADR_T9_AMPHYST                              0x11
/* 16 bit */
#define MXT_ADR_T9_XRANGE                               0x12
/* 16 bit */
#define MXT_ADR_T9_YRANGE                               0x14
#define MXT_ADR_T9_XLOCLIP                              0x16
#define MXT_ADR_T9_XHICLIP                              0x17
#define MXT_ADR_T9_YLOCLIP                              0x18
#define MXT_ADR_T9_YHICLIP                              0x19
#define MXT_ADR_T9_XEDGECTRL                            0x1a
#define MXT_ADR_T9_XEDGEDIST                            0x1b
#define MXT_ADR_T9_YEDGECTRL                            0x1c
#define MXT_ADR_T9_YEDGEDIST                            0x1d

/* TOUCH_KEYARRAY_T15 Address Definitions               */

#define MXT_ADR_T15_CTRL                                0x00
#define MXT_T15_CFGB_ENABLE(x)                         (((x) >> 0) & 0x01)
#define MXT_T15_CFGB_RPRTEN(x)                         (((x) >> 1) & 0x01)
#define MXT_T15_CFGB_INTAKSEN(x)                       (((x) >> 7) & 0x01)
#define MXT_ADR_T15_XORIGIN                             0x01
#define MXT_ADR_T15_YORIGIN                             0x02
#define MXT_ADR_T15_XSIZE                               0x03
#define MXT_ADR_T15_YSIZE                               0x04
#define MXT_ADR_T15_AKSCFG                              0x05
#define MXT_ADR_T15_BLEN                                0x06
#define MXT_T15_CFGBF_BL(x)                             (x & 0x0F)
#define MXT_T15_CFGBF_GAIN(x)                           ((x >> 4) & 0x0F)
#define MXT_ADR_T15_TCHTHR                              0x07
#define MXT_ADR_T15_TCHDI                               0x08
#define MXT_ADR_T15_RESERVED1                           0x09
#define MXT_ADR_T15_RESERVED2                           0x0a


/* Adress Definitions for SPT_GPIOPWM_T19 Address Definitions           */
#define MXT_ADR_T19_CTRL                                0x00
#define MXT_ADR_T19_REPORTMASK                          0x01
#define MXT_ADR_T19_DIR                                 0x02
#define MXT_ADR_T19_INTPULLUP                           0x03
#define MXT_ADR_T19_OUT                                 0x04
#define MXT_ADR_T19_WAKE                                0x05
#define MXT_ADR_T19_PWM                                 0x06
#define MXT_ADR_T19_PERIOD                              0x07
/* 32 bit */
#define MXT_ADR_T19_DUTY                                0x08

/* PROCI_GRIPFACESUPPRESSION_T20 Address Definitions            */
#define MXT_ADR_T20_CTRL                                0x00
#define MXT_ADR_T20_XLOGRIP                             0x01
#define MXT_ADR_T20_XHIGRIP                             0x02
#define MXT_ADR_T20_YLOGRIP                             0x03
#define MXT_ADR_T20_YHIGRIP                             0x04
#define MXT_ADR_T20_MAXTCHS                             0x05
#define MXT_ADR_T20_RESERVED                            0x06
#define MXT_ADR_T20_SZTHR1                              0x07
#define MXT_ADR_T20_SZTHR2                              0x08
#define MXT_ADR_T20_SHPTHR1                             0x09
#define MXT_ADR_T20_SHPTHR2                             0x0a
#define MXT_ADR_T20_SUPEXTTO                            0x0b

/* PROCG_NOISESUPPRESSION_T22 Address Definitions               */
#define MXT_ADR_T22_CTRL                                0x00
/* 16 bit */
#define MXT_ADR_T22_RESERVED1_2                         0x01
/* 16 bit */
#define MXT_ADR_T22_GCAFUL                              0x03
/* 16 bit */
#define MXT_ADR_T22_GCAFLL                              0x05
#define MXT_ADR_T22_ACTVGCAFVALID                       0x07
#define MXT_ADR_T22_NOISETHR                            0x08
#define MXT_ADR_T22_RESERVED9                           0x09
#define MXT_ADR_T22_FREQHOPSCALE                        0x0A
/* 5 bytes */
#define MXT_ADR_T22_FREQ                                0x0B
#define MXT_ADR_T22_IDLEGCAFVALID                       0x10

/* TOUCH_PROXIMITY_T23 Address Definitions              */
#define MXT_ADR_T23_CTRL                                0x00
#define MXT_ADR_T23_XORIGIN                             0x01
#define MXT_ADR_T23_YORIGIN                             0x02
#define MXT_ADR_T23_XSIZE                               0x03
#define MXT_ADR_T23_YSIZE                               0x04
#define MXT_ADR_T23_RESERVED                            0x05
#define MXT_ADR_T23_BLEN                                0x06
#define MXT_ADR_T23_TCHTHR                              0x07
#define MXT_ADR_T23_TCHDI                               0x09
#define MXT_ADR_T23_AVERAGE                             0x0a
/* 16 bit */
#define MXT_ADR_T23_RATE                                0x0b

/* PROCI_ONETOUCHGESTUREPROCESSOR_T24 Address Definitions               */
#define MXT_ADR_T24_CTRL                                0x00
#define MXT_ADR_T24_NUMGEST                             0x01
/* 16 bit */
#define MXT_ADR_T24_GESTEN                              0x02
#define MXT_ADR_T24_PRESSPROC                           0x04
#define MXT_ADR_T24_TAPTO                               0x05
#define MXT_ADR_T24_FLICKTO                             0x06
#define MXT_ADR_T24_DRAGTO                              0x07
#define MXT_ADR_T24_SPRESSTO                            0x08
#define MXT_ADR_T24_LPRESSTO                            0x09
#define MXT_ADR_T24_REPPRESSTO                          0x0a
/* 16 bit */
#define MXT_ADR_T24_FLICKTHR                            0x0b
/* 16 bit */
#define MXT_ADR_T24_DRAGTHR                             0x0d
/* 16 bit */
#define MXT_ADR_T24_TAPTHR                              0x0f
/* 16 bit */
#define MXT_ADR_T24_THROWTHR                            0x11

/* SPT_SELFTEST_T25 Address Definitions         */
#define MXT_ADR_T25_CTRL                                0x00
#define MXT_ADR_T25_CMD                                 0x01
/* 16 bit */
#define MXT_ADR_T25_HISIGLIM0                           0x02
/* 16 bit */
#define MXT_ADR_T25_LOSIGLIM0                           0x04

/* PROCI_TWOTOUCHGESTUREPROCESSOR_T27 Address Definitions               */
#define MXT_ADR_T27_CTRL                                0x00
#define MXT_ADR_T27_NUMGEST                             0x01
#define MXT_ADR_T27_RESERVED2                           0x02
#define MXT_ADR_T27_GESTEN                              0x03
#define MXT_ADR_T27_ROTATETHR                           0x04

/* 16 bit */
#define MXT_ADR_T27_ZOOMTHR                             0x05

/* SPT_CTECONFIG_T28 Address Definitions                */
#define MXT_ADR_T28_CTRL                                0x00
#define MXT_ADR_T28_CMD                                 0x01
#define MXT_ADR_T28_MODE                                0x02
#define MXT_ADR_T28_IDLEGCAFDEPTH                       0x03
#define MXT_ADR_T28_ACTVGCAFDEPTH                       0x04

/* DEBUG_DIAGNOSTICS_T37 Address Definitions            */
#define MXT_ADR_T37_MODE                                0x00
#define MXT_ADR_T37_PAGE                                0x01
#define MXT_ADR_T37_DATA                                0x02


#if 1
/* PROCI_GRIPSUPPRESSION_T40 */

#define MXT_ADR_T40_CTRL                                0x00
#define MXT_ADR_T40_XLOGRIP                             0x01
#define MXT_ADR_T40_XHIGRIP                             0x02
#define MXT_ADR_T40_YLOGRIP                             0x03
#define MXT_ADR_T40_YHIGRIP                             0x04

/* PROCI_TOUCHSUPPRESSION_T42 */
#define MXT_ADR_T42_CTRL                                0x00
#define MXT_ADR_T42_APPRTHR                             0x01   /* 0 (TCHTHR/4), 1 to 255 */
#define MXT_ADR_T42_MAXAPPRAREA                         0x02   /* 0 (40ch), 1 to 255 */
#define MXT_ADR_T42_MAXTCHAREA                          0x03   /* 0 (35ch), 1 to 255 */
#define MXT_ADR_T42_SUPSTRENGTH                         0x04   /* 0 (128), 1 to 255 */
#define MXT_ADR_T42_SUPEXTTO                            0x05   /* 0 (never expires), 1 to 255 (timeout in cycles) */
#define MXT_ADR_T42_MAXNUMTCHS                          0x06   /* 0 to 9 (maximum number of touches minus 1) */
#define MXT_ADR_T42_SHAPESTRENGTH                       0x07   /* 0 (10), 1 to 31 */


/* SPT_CTECONFIG_T46  */
#define MXT_ADR_T46_CTRL                                0x00  /* Reserved */
#define MXT_T46_CFGB_ENABLE(x)                         (((x) >> 0) & 0x01)
#define MXT_ADR_T46_MODE                                0x01  /* 0: 16X14Y, 1: 17X13Y, 2: 18X12Y, 3: 19X11Y, 4: 20X10Y, 5: 21X15Y, 6: 22X8Y, */
#define MXT_ADR_T46_IDLESYNCSPERX                       0x02
#define MXT_ADR_T46_ACTVSYNCSPERX                       0x03
#define MXT_ADR_T46_ADCSPERSYNC                         0x04
#define MXT_ADR_T46_PULSESPERADC                        0x05  /* 0:1  1:2   2:3   3:4 pulses */
#define MXT_ADR_T46_XSLEW                               0x06  /* 1:500nsec,  0:350nsec */


/* PROCI_STYLUS_T47 */
#define MXT_ADR_T47_CTRL                                0x00
#define MXT_ADR_T47_CONTMIN                             0x01
#define MXT_ADR_T47_CONTMAX                             0x02
#define MXT_ADR_T47_STABILITY                           0x03
#define MXT_ADR_T47_MAXTCHAREA                          0x04
#define MXT_ADR_T47_AMPLTHR                             0x05
#define MXT_ADR_T47_STYSHAPE                            0x06
#define MXT_ADR_T47_HOVERSUP                            0x07
#define MXT_ADR_T47_CONFTHR                             0x08
#define MXT_ADR_T47_SYNCSPERX                           0x09


/* PROCG_NOISESUPPRESSION_T48  */
#define MXT_ADR_T48_CTRL                                0x00
#define MXT_T48_CFGB_ENABLE(x)                         (((x) >> 0) & 0x01)
#define MXT_T48_CFGB_RPRTEN(x)                         (((x) >> 1) & 0x01)
#define MXT_T48_CFGB_RPTFREQ(x)                        (((x) >> 2) & 0x01)
#define MXT_T48_CFGB_RPTAPX(x)                         (((x) >> 3) & 0x01)

#define MXT_ADR_T48_CFG                                 0x01
#define MXT_T48_CFGBF_GCMODE(x)                         (((x) >> 0) & 0x07)

#define MXT_ADR_T48_CALCFG                              0x02
#define MXT_T48_CFGB_NLEN(x)                            (((x) >> 0) & 0x01)
#define MXT_T48_CFGB_MFEN(x)                            (((x) >> 1) & 0x01)
#define MXT_T48_CFGB_FIXFREQ(x)                         (((x) >> 2) & 0x01)
#define MXT_T48_CFGB_INCBIAS(x)                         (((x) >> 6) & 0x01)
#define MXT_T48_CFGB_INCRST(x)                          (((x) >> 7) & 0x01)

#define MXT_ADR_T48_BASEFREQ                            0x03
#define MXT_ADR_T48_FREQ_0                              0x04
#define MXT_ADR_T48_FREQ_1                              0x05
#define MXT_ADR_T48_FREQ_2                              0x06
#define MXT_ADR_T48_FREQ_3                              0x07
#define MXT_ADR_T48_MFFREQ_2                            0x08
#define MXT_ADR_T48_MFFREQ_3                            0x09
#define MXT_ADR_T48_NLGAIN                              0x0a
#define MXT_T48_CFGBF_GAIN(x)                          (((x) >> 4) & 0x0F)
#define MXT_ADR_T48_NLTHR                               0x0b
#define MXT_ADR_T48_GCLIMIT                             0x0c
#define MXT_ADR_T48_GCACTVINVLDADCS                     0x0d
#define MXT_ADR_T48_GCIDLEINVLDADCS                     0x0e
#define MXT_ADR_T48_GCINVALIDTHR                        0x0f
#define MXT_ADR_T48_GCMAXADCSPERX                       0x10

#endif



/************************************************************************
* MESSAGE OBJECTS ADDRESS FIELDS
*
************************************************************************/
#define MXT_MSG_REPORTID                                0x00


/* MXT_GEN_MESSAGEPROCESSOR_T5 Message address definitions              */
#define MXT_MSG_T5_REPORTID                             0x00
#define MXT_MSG_T5_MESSAGE                              0x01
#define MXT_MSG_T5_CHECKSUM                             0x08

/* MXT_GEN_COMMANDPROCESSOR_T6 Message address definitions              */
#define MXT_MSG_T6_STATUS                               0x01
#define MXT_MSGB_T6_COMSERR                             0x04
#define MXT_MSGB_T6_CFGERR                              0x08
#define MXT_MSGB_T6_CAL                                 0x10
#define MXT_MSGB_T6_SIGERR                              0x20
#define MXT_MSGB_T6_OFL                                 0x40
#define MXT_MSGB_T6_RESET                               0x80
/* Three bytes */
#define MXT_MSG_T6_CHECKSUM                             0x02

/* MXT_GEN_POWERCONFIG_T7 NO Message address definitions                */
/* MXT_GEN_ACQUIRECONFIG_T8 Message address definitions                 */
/* MXT_TOUCH_MULTITOUCHSCREEN_T9 Message address definitions            */

#define MXT_MSG_T9_STATUS                               0x01
/* Status bit field */
#define MXT_MSGB_T9_SUPPRESS                            0x02
#define MXT_MSGB_T9_AMP                                 0x04
#define MXT_MSGB_T9_VECTOR                              0x08
#define MXT_MSGB_T9_MOVE                                0x10
#define MXT_MSGB_T9_RELEASE                             0x20
#define MXT_MSGB_T9_PRESS                               0x40
#define MXT_MSGB_T9_DETECT                              0x80

#define MXT_MSG_T9_XPOSMSB                              0x02
#define MXT_MSG_T9_YPOSMSB                              0x03
#define MXT_MSG_T9_XYPOSLSB                             0x04
#define MXT_MSG_T9_TCHAREA                              0x05
#define MXT_MSG_T9_TCHAMPLITUDE                         0x06
#define MXT_MSG_T9_TCHVECTOR                            0x07

/* MXT_TOUCH_KEYARRAY_T15 Message address definitions                   */
#define MXT_MSG_T15_STATUS                              0x01
#define MXT_MSGB_T15_DETECT                             0x80
/* 4 bytes */
#define MXT_MSG_T15_KEYSTATE                            0x02

/* MXT_SPT_GPIOPWM_T19 Message address definitions                      */
#define MXT_MSG_T19_STATUS                              0x01

/* MXT_PROCI_GRIPFACESUPPRESSION_T20 Message address definitions        */
#define MXT_MSG_T20_STATUS                              0x01
#define MXT_MSGB_T20_FACE_SUPPRESS                      0x01
/* MXT_PROCG_NOISESUPPRESSION_T22 Message address definitions           */
#define MXT_MSG_T22_STATUS                              0x01
#define MXT_MSGB_T22_FHCHG                              0x01
#define MXT_MSGB_T22_GCAFERR                            0x04
#define MXT_MSGB_T22_FHERR                              0x08
#define MXT_MSG_T22_GCAFDEPTH                           0x02

/* MXT_TOUCH_PROXIMITY_T23 Message address definitions                  */
#define MXT_MSG_T23_STATUS                              0x01
#define MXT_MSGB_T23_FALL                               0x20
#define MXT_MSGB_T23_RISE                               0x40
#define MXT_MSGB_T23_DETECT                             0x80
/* 16 bit */
#define MXT_MSG_T23_PROXDELTA                           0x02

/* MXT_PROCI_ONETOUCHGESTUREPROCESSOR_T24 Message address definitions   */
#define MXT_MSG_T24_STATUS                              0x01
#define MXT_MSG_T24_XPOSMSB                             0x02
#define MXT_MSG_T24_YPOSMSB                             0x03
#define MXT_MSG_T24_XYPOSLSB                            0x04
#define MXT_MSG_T24_DIR                                 0x05
/* 16 bit */
#define MXT_MSG_T24_DIST                                0x06

/* MXT_SPT_SELFTEST_T25 Message address definitions                     */
#define MXT_MSG_T25_STATUS                              0x01
/* 5 Bytes */
#define MXT_MSGR_T25_OK                                 0xFE
#define MXT_MSGR_T25_INVALID_TEST                       0xFD
#define MXT_MSGR_T25_PIN_FAULT                          0x11
#define MXT_MSGR_T25_SIGNAL_LIMIT_FAULT                 0x17
#define MXT_MSGR_T25_GAIN_ERROR                         0x20
#define MXT_MSG_T25_INFO                                0x02

/* MXT_PROCI_TWOTOUCHGESTUREPROCESSOR_T27 Message address definitions   */
#define MXT_MSG_T27_STATUS                              0x01
#define MXT_MSGB_T27_ROTATEDIR                          0x10
#define MXT_MSGB_T27_PINCH                              0x20
#define MXT_MSGB_T27_ROTATE                             0x40
#define MXT_MSGB_T27_STRETCH                            0x80
#define MXT_MSG_T27_XPOSMSB                             0x02
#define MXT_MSG_T27_YPOSMSB                             0x03
#define MXT_MSG_T27_XYPOSLSB                            0x04
#define MXT_MSG_T27_ANGLE                               0x05

/* 16 bit */
#define MXT_MSG_T27_SEPARATION                          0x06

/* MXT_SPT_CTECONFIG_T28 Message address definitions                    */
#define MXT_MSG_T28_STATUS                              0x01
#define MXT_MSGB_T28_CHKERR                             0x01


/* MXT_PROCI_TOUCHSUPPRESSION_T42 Message address fifinitions */
#define MXT_MSG_T42_STATUS                               0x01


/* MXT_SPT_CTECONFIG_T46 Message address fifinitions */
#define MXT_MSG_T46_STATUS                               0x01
#define MXT_MSGB_T46_CHKERR                              0x01



/* MXT_PROCG_NOISESUPPRESSION_T48 Message address fifinitions */
#define MXT_MSG_T48_STATUS                               0x01
#define MXT_MSGB_T48_FREQCHG                             0x01
#define MXT_MSGB_T48_APXCHG                              0x02
#define MXT_MSGB_T48_ALGOERR                             0x04
#define MXT_MSGB_T27_ISACTIV                             0x08

#define MXT_MSG_T48_ADCSPERX                             0x02
#define MXT_MSG_T48_FREQ                                 0x03

/* Three bytes */




/* MXT_DEBUG_DIAGNOSTICS_T37 NO Message address definitions             */

/* One Touch Events */
#define MT_GESTURE_RESERVED                             0x00
#define MT_GESTURE_PRESS                                0x01
#define MT_GESTURE_RELEASE                              0x02
#define MT_GESTURE_TAP                                  0x03
#define MT_GESTURE_DOUBLE_TAP                           0x04
#define MT_GESTURE_FLICK                                0x05
#define MT_GESTURE_DRAG                                 0x06
#define MT_GESTURE_SHORT_PRESS                          0x07
#define MT_GESTURE_LONG_PRESS                           0x08
#define MT_GESTURE_REPEAT_PRESS                         0x09
#define MT_GESTURE_TAP_AND_PRESS                        0x0a
#define MT_GESTURE_THROW                                0x0b

/* reset mode */
#define RESET_TO_NORMAL                                 0
#define RESET_TO_BOOTLOADER                             1

/* Bootloader states */
#define WAITING_BOOTLOAD_COMMAND                        0xC0
#define WAITING_FRAME_DATA                              0x80
#define FRAME_CRC_CHECK                                 0x02
#define FRAME_CRC_PASS                                  0x04
#define FRAME_CRC_FAIL                                  0x03
#define APP_CRC_FAIL                                    0x40
#define BOOTLOAD_STATUS_MASK                            0x3f

#define MXT_MAX_FRAME_SIZE                              532

/* Firmware */
#define MXT224E_FIRMWARE "mxt224e.fw"

/* level of debugging messages */
#define DEBUG_INFO      1
#define DEBUG_VERBOSE   2
#define DEBUG_MESSAGES  5
#define DEBUG_RAW       8
#define DEBUG_TRACE     10

#define klogi(fmt, arg...)  printk(KERN_INFO "%s: " fmt "\n" , __func__, ## arg)
#define kloge(fmt, arg...)  printk(KERN_ERR "%s(%d): " fmt "\n" , __func__, __LINE__, ## arg)
#define klogi_if(fmt, arg...) if (mxt_debug) printk(KERN_INFO "%s: " fmt "\n" , __func__, ## arg)
#define kloge_if(fmt, arg...) if (mxt_debug) printk(KERN_ERR "%s(%d): " fmt "\n" , __func__, __LINE__, ## arg)

#define MIGRATION_TO_NVODM

/* Device Info descriptor */
/* Parsed from maXTouch "Id information" inside device */
struct mxt_device_info {
	u8      family_id;
	u8      variant_id;
	u8      major;
	u8      minor;
	u8      build;
	u8      num_objs;
	u8      x_size;
	u8      y_size;
	u8      family[16];     /* Family name */
	u8      variant[16];    /* Variant name */
	u16     num_nodes;      /* Number of sensor nodes */
};

/* object descriptor table, parsed from maXTouch "object table" */
struct mxt_object {
	u8      type;
	u16     chip_addr;
	u8      size;
	u8      instances;
	u8      num_report_ids;
};

/* Mapping from report id to object type and instance */
struct report_id_map {
	u8  object;
	u8  instance;
	/*
	* This is the first report ID belonging to object. It enables us to
	* find out easily the touch number: each touch has different report
	* ID (which are assigned to touches in increasing order). By
	* subtracting the first report ID from current, we get the touch
	* number.
	*/
	u8  first_rid;
};

/* Driver datastructure */
struct mxt_data {
	struct i2c_client *client;
	struct input_dev  *input;
	char              phys_name[32];
	int               irq;

	u16               last_read_addr;
	bool              new_msgs;
	u8                *last_message;

	wait_queue_head_t msg_queue;
	struct semaphore  msg_sem;

	int               valid_irq_counter;
	int               invalid_irq_counter;
	int               irq_counter;
	int               message_counter;
	int               read_fail_counter;


	int               bytes_to_read;

	/* Protect canceling/rescheduling of dwork */
	spinlock_t           lock;
	struct delayed_work  dwork;
#if defined(CONFIG_MACH_N1) || defined(CONFIG_MACH_JANICE)
	struct delayed_work  firmup_dwork;
#endif
	u8                   xpos_format;
	u8                   ypos_format;

	u8                   numtouch;
	int   		     rotate;	/* if rotated by 180 or not */

	struct mxt_device_info  device_info;

	u32                  info_block_crc;
	u32                  configuration_crc;
	u16                  report_id_count;
	struct report_id_map *rid_map;
	struct mxt_object    *object_table;

	u16                  msg_proc_addr;
	u8                   message_size;

	/* Pointers to diagnostic objects, not allocated, unless needed */
	s16                  *delta;
	u16                  *reference;
	u16                  *cte;

	u16                  max_x_val;
	u16                  max_y_val;

	void                 (*init_hw)(void);
	void                 (*exit_hw)(void);
#if defined(CONFIG_MACH_N1) || defined(CONFIG_MACH_JANICE)
	void                 (*suspend_hw)(void);
	void                 (*resume_hw)(void);
	struct regulator *reg_avdd;  /* TSP_AVDD_3.3V */
	struct regulator *reg_vdd;  /* TSP_VDD_1.8V */
#endif
	struct wake_lock wakelock;
#ifdef CONFIG_HAS_EARLYSUSPEND
	struct early_suspend    early_suspend;
#endif
};

/* Returns the start address of object in mXT memory. */
#define MXT_BASE_ADDR(object_type) \
mxt_get_object_address(object_type, 0, mxt->object_table, mxt->device_info.num_objs)

/* Returns the size of object in mXT memory. */
#define MXT_GET_SIZE(object_type) \
mxt_get_object_size(object_type, mxt->object_table, mxt->device_info.num_objs)

/* Routines for memory access within a 16 bit address space */
int mxt_read_byte(
				  struct i2c_client *client,
				  __u16 addr,
				  __u8 *value
				  );
int mxt_read__block(
					struct i2c_client *client,
					__u16 addr,
					__u16 length,
					__u8 *value
					);
int mxt_write_byte(
				   struct i2c_client *client,
				   __u16 addr,
				   __u8 value
				   );
int mxt_write_block(
					struct i2c_client *client,
					__u16 addr,
					__u16 length,
					__u8 *value
					);


int mxt_read_byte_bl(
					 struct i2c_client *client,
					 __u8 *value
					 );
int mxt_read__block_bl(
					   struct i2c_client *client,
					   __u16 length,
					   __u8 *value
					   );
int mxt_write_byte_bl(
					  struct i2c_client *client,
					  __u8 value
					  );
int mxt_write_block_bl(
					   struct i2c_client *client,
					   __u16 length,
					   __u8 *value
					   );

struct mxt_platform_data {
	u8    numtouch; /* Number of touches to report  */
	int   rotate;	/* if rotated by 180 or not */
	void  (*init_platform_hw)(void);
	void  (*exit_platform_hw)(void);
	void  (*suspend_platform_hw)(void);
	void  (*resume_platform_hw)(void);
	int   max_x;    /* The default reported X range   */
	int   max_y;    /* The default reported Y range   */
	u8    (*valid_interrupt) (void);
	int		scl_gpio;		/* GPIO for I2C clock - used for firmware update */
	int		sda_gpio;		/* GPIO for I2C data - used for firmware update */

};


#if     1
/* Should be implemented in board support */
u8 mxt_valid_interrupt(void);
#else
#define mxt_valid_interrupt()    1
#endif


void    mxt_hw_reset(void);







