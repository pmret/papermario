#include "common.h"
#include "ld_addrs.h"

typedef struct BattleArea {
    /* 0x00 */ char* name; ///< JP debug name.
    /* 0x04 */ s32 dmaStart;
    /* 0x08 */ s32 dmaEnd;
    /* 0x0C */ void* dmaDest;
    /* 0x10 */ void* formations;
    /* 0x14 */ void* stages;
    /* 0x18 */ s32 unused_18;
    /* 0x1C */ void* dmaTable;
} BattleArea; // size = 0x20

#define AREA(id) \
    .dmaStart = &code_##id##_ROM_START, \
    .dmaEnd = &code_##id##_ROM_END, \
    .dmaDest = &code_##id##_VRAM

// help
const s32 lol[] = {
    0x08080808, 0x08080808, 0x08080808, 0x08080808,
    0x08080808, 0x08080808, 0x08080808, 0x08080808,
    0x08080808, 0x08080808, 0x08080808, 0x08080808,
    0x08080808, 0x08080808, 0x08080808, 0x08080808,

    0x08080808, 0x08080808, 0x08080808, 0x08080808,
    0x08080808, 0x08080808, 0x08080808, 0x08080808,
    0x08080808, 0x08080808, 0x08080808, 0x08080808,
    0x08080808, 0x08080808, 0x08080808, 0x08080808,
};

BattleArea gBattleAreas[] = {
    {
        AREA(section_0),
        .name = "エリア ＫＭＲ その１",
        .formations = 0x802194D4,
        .stages = 0x802195D8,
    },
    {
        AREA(section_1),
        .name = "エリア ＫＭＲ その２",
        .formations = 0x80219840,
        .stages = 0x8021987C,
    },
    {
        AREA(section_2),
        .name = "エリア ＫＭＲ その３",
        .formations = 0x8021A2AC,
        .stages = 0x8021A360,
    },
    {
        AREA(section_3),
        .name = "エリア ＭＡＣ",
        .formations = 0x80232A5C,
        .stages = 0x80232AD4,
    },
    {
        AREA(section_4),
        .name = "エリア ＨＯＳ",
        .formations = 0x80225F24,
        .stages = 0x80225F88,
    },
    {
        AREA(section_5),
        .name = "エリア ＮＯＫ",
        .formations = 0x80219520,
        .stages = 0x80219728,
    },
    {
        AREA(section_6),
        .name = "エリア ＴＲＤ その１",
        .formations = 0x80218CB0,
        .stages = 0x80218EE0,
    },
    {
        AREA(section_7),
        .name = "エリア ＴＲＤ その２",
        .formations = 0x8021A5DC,
        .stages = 0x8021A604,
    },
    {
        AREA(section_8),
        .name = "エリア ＴＲＤ その３",
        .formations = 0x8021823C,
        .stages = 0x80218264,
    },
    {
        AREA(section_9),
        .name = "エリア ＩＷＡ",
        .formations = 0x802185B8,
        .stages = 0x802186E4,
    },
    {
        AREA(section_10),
        .name = "エリア ＳＢＫ",
        .formations = 0x8021FE80,
        .stages = 0x8021FFE8,
    },
    {
        AREA(section_11),
        .name = "エリア ＩＳＫ その１",
        .formations = 0x80224700,
        .stages = 0x802248A4,
    },
    {
        AREA(section_12),
        .name = "エリア ＩＳＫ その２",
        .formations = 0x80220448,
        .stages = 0x80220470,
    },
    {
        AREA(section_13),
        .name = "エリア ＭＩＭ",
        .formations = 0x8021EA70,
        .stages = 0x8021EBEC,
    },
    {
        AREA(section_14),
        .name = "エリア ＡＲＮ",
        .formations = 0x80228110,
        .stages = 0x80228278,
    },
    {
        AREA(section_15),
        .name = "0x8009A438",
        .formations = 0x8021B38C,
        .stages = 0x8021B418,
    },
    {
        AREA(section_16),
        .name = "エリア ＯＭＯ",
        .formations = 0x80230730,
        .stages = 0x80230AC8,
    },
    {
        AREA(section_17),
        .name = "エリア ＯＭＯ２",
        .formations = 0x8022FBF4,
        .stages = 0x8022FC1C,
    },
    {
        AREA(section_18),
        .name = "エリア ＯＭＯ３",
        .formations = 0x8022EA2C,
        .stages = 0x8022EB1C,
    },
    {
        AREA(section_19),
        .name = "エリア ＫＧＲ",
        .formations = 0x8021D5FC,
        .stages = 0x8021D624,
    },
    {
        AREA(section_20),
        .name = "エリア ＪＡＮ",
        .formations = 0x80228AF8,
        .stages = 0x80228C60,
    },
    {
        AREA(section_21),
        .name = "エリア ＪＡＮ２",
        .formations = 0x8021F6C8,
        .stages = 0x8021F72C,
    },
    {
        AREA(section_22),
        .name = "エリア ＫＺＮ",
        .formations = 0x80229E74,
        .stages = 0x8022A02C,
    },
    {
        AREA(section_23),
        .name = "エリア ＫＺＮ２",
        .formations = 0x8022AA08,
        .stages = 0x8022AA44,
        .dmaTable = 0x8022AA84,
    },
    {
        AREA(section_24),
        .name = "エリア ＦＬＯ",
        .formations = 0x80234574,
        .stages = 0x8023486C,
    },
    {
        AREA(section_25),
        .name = "エリア ＦＬＯ２",
        .formations = 0x802356FC,
        .stages = 0x80235788,
    },
    {
        AREA(section_26),
        .name = "エリア ＴＩＫ",
        .formations = 0x802340B4,
        .stages = 0x802342BC,
    },
    {
        AREA(section_27),
        .name = "エリア ＴＩＫ２",
        .formations = 0x80227A90,
        .stages = 0x80227AE0,
    },
    {
        AREA(section_28),
        .name = "エリア ＴＩＫ３",
        .formations = 0x802232E8,
        .stages = 0x8022334C,
    },
    {
        AREA(section_29),
        .name = "エリア ＳＡＭ",
        .formations = 0x80231164,
        .stages = 0x80231290,
    },
    {
        AREA(section_30),
        .name = "エリア ＳＡＭ２",
        .formations = 0x802234F0,
        .stages = 0x8022352C,
    },
    {
        AREA(section_31),
        .name = "エリア ＰＲＡ",
        .formations = 0x8022F4D4,
        .stages = 0x8022F614,
    },
    {
        AREA(section_32),
        .name = "エリア ＰＲＡ２",
        .formations = 0x802215A0,
        .stages = 0x802215C8,
    },
    {
        AREA(section_33),
        .name = "エリア ＰＲＡ３",
        .formations = 0x80232888,
        .stages = 0x8023298C,
    },
    {
        AREA(section_34),
        .name = "エリア ＫＰＡ",
        .formations = 0x80231A64,
        .stages = 0x80231ED8,
    },
    {
        AREA(section_35),
        .name = "エリア ＫＰＡ２",
        .formations = 0x802346A8,
        .stages = 0x80234720,
    },
    {
        AREA(section_36),
        .name = "エリア ＫＰＡ３",
        .formations = 0x8022839C,
        .stages = 0x802283EC,
    },
    {
        AREA(section_37),
        .name = "エリア ＫＰＡ４",
        .formations = 0x80227910,
        .stages = 0x80227988,
    },
    {
        AREA(section_38),
        .name = "エリア ＫＫＪ",
        .formations = 0x802185BC,
        .stages = 0x802185E4,
    },
    {
        AREA(section_39),
        .name = "エリア ＤＩＧ",
        .formations = 0x8022A7C4,
        .stages = 0x8022A83C,
    },
    {},
    {
        AREA(section_41),
        .name = "エリア ＯＭＯ２＿１",
    },
    {
        AREA(section_42),
        .name = "エリア ＯＭＯ２＿２",
    },
    {
        AREA(section_43),
        .name = "エリア ＯＭＯ２＿３",
    },
    {
        AREA(section_44),
        .name = "エリア ＯＭＯ２＿４",
    },
    {
        AREA(section_45),
        .name = "エリア ＯＭＯ２＿５",
    },
    {
        AREA(section_46),
        .name = "エリア ＯＭＯ２＿６",
    },
    {},
};
