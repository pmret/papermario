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
        AREA(area_kmr_part_1),
        .name = "エリア ＫＭＲ その１",
        .formations = 0x802194D4,
        .stages = 0x802195D8,
    },
    {
        AREA(area_kmr_part_2),
        .name = "エリア ＫＭＲ その２",
        .formations = 0x80219840,
        .stages = 0x8021987C,
    },
    {
        AREA(area_kmr_part_3),
        .name = "エリア ＫＭＲ その３",
        .formations = 0x8021A2AC,
        .stages = 0x8021A360,
    },
    {
        AREA(area_mac),
        .name = "エリア ＭＡＣ",
        .formations = 0x80232A5C,
        .stages = 0x80232AD4,
    },
    {
        AREA(area_hos),
        .name = "エリア ＨＯＳ",
        .formations = 0x80225F24,
        .stages = 0x80225F88,
    },
    {
        AREA(area_nok),
        .name = "エリア ＮＯＫ",
        .formations = 0x80219520,
        .stages = 0x80219728,
    },
    {
        AREA(area_trd_part_1),
        .name = "エリア ＴＲＤ その１",
        .formations = 0x80218CB0,
        .stages = 0x80218EE0,
    },
    {
        AREA(area_trd_part_2),
        .name = "エリア ＴＲＤ その２",
        .formations = 0x8021A5DC,
        .stages = 0x8021A604,
    },
    {
        AREA(area_trd_part_3),
        .name = "エリア ＴＲＤ その３",
        .formations = 0x8021823C,
        .stages = 0x80218264,
    },
    {
        AREA(area_iwa),
        .name = "エリア ＩＷＡ",
        .formations = 0x802185B8,
        .stages = 0x802186E4,
    },
    {
        AREA(area_sbk),
        .name = "エリア ＳＢＫ",
        .formations = 0x8021FE80,
        .stages = 0x8021FFE8,
    },
    {
        AREA(area_isk_part_1),
        .name = "エリア ＩＳＫ その１",
        .formations = 0x80224700,
        .stages = 0x802248A4,
    },
    {
        AREA(area_isk_part_2),
        .name = "エリア ＩＳＫ その２",
        .formations = 0x80220448,
        .stages = 0x80220470,
    },
    {
        AREA(area_mim),
        .name = "エリア ＭＩＭ",
        .formations = 0x8021EA70,
        .stages = 0x8021EBEC,
    },
    {
        AREA(area_arn),
        .name = "エリア ＡＲＮ",
        .formations = 0x80228110,
        .stages = 0x80228278,
    },
    {
        AREA(area_dgb),
        .name = "エリア ＤＧＢ",
        .formations = 0x8021B38C,
        .stages = 0x8021B418,
    },
    {
        AREA(area_omo),
        .name = "エリア ＯＭＯ",
        .formations = 0x80230730,
        .stages = 0x80230AC8,
    },
    {
        AREA(area_omo2),
        .name = "エリア ＯＭＯ２",
        .formations = 0x8022FBF4,
        .stages = 0x8022FC1C,
    },
    {
        AREA(area_omo3),
        .name = "エリア ＯＭＯ３",
        .formations = 0x8022EA2C,
        .stages = 0x8022EB1C,
    },
    {
        AREA(area_kgr),
        .name = "エリア ＫＧＲ",
        .formations = 0x8021D5FC,
        .stages = 0x8021D624,
    },
    {
        AREA(area_jan),
        .name = "エリア ＪＡＮ",
        .formations = 0x80228AF8,
        .stages = 0x80228C60,
    },
    {
        AREA(area_jan2),
        .name = "エリア ＪＡＮ２",
        .formations = 0x8021F6C8,
        .stages = 0x8021F72C,
    },
    {
        AREA(area_kzn),
        .name = "エリア ＫＺＮ",
        .formations = 0x80229E74,
        .stages = 0x8022A02C,
    },
    {
        AREA(area_kzn2),
        .name = "エリア ＫＺＮ２",
        .formations = 0x8022AA08,
        .stages = 0x8022AA44,
        .dmaTable = 0x8022AA84,
    },
    {
        AREA(area_flo),
        .name = "エリア ＦＬＯ",
        .formations = 0x80234574,
        .stages = 0x8023486C,
    },
    {
        AREA(area_flo2),
        .name = "エリア ＦＬＯ２",
        .formations = 0x802356FC,
        .stages = 0x80235788,
    },
    {
        AREA(area_tik),
        .name = "エリア ＴＩＫ",
        .formations = 0x802340B4,
        .stages = 0x802342BC,
    },
    {
        AREA(area_tik2),
        .name = "エリア ＴＩＫ２",
        .formations = 0x80227A90,
        .stages = 0x80227AE0,
    },
    {
        AREA(area_tik3),
        .name = "エリア ＴＩＫ３",
        .formations = 0x802232E8,
        .stages = 0x8022334C,
    },
    {
        AREA(area_sam),
        .name = "エリア ＳＡＭ",
        .formations = 0x80231164,
        .stages = 0x80231290,
    },
    {
        AREA(area_sam2),
        .name = "エリア ＳＡＭ２",
        .formations = 0x802234F0,
        .stages = 0x8022352C,
    },
    {
        AREA(area_pra),
        .name = "エリア ＰＲＡ",
        .formations = 0x8022F4D4,
        .stages = 0x8022F614,
    },
    {
        AREA(area_pra2),
        .name = "エリア ＰＲＡ２",
        .formations = 0x802215A0,
        .stages = 0x802215C8,
    },
    {
        AREA(area_pra3),
        .name = "エリア ＰＲＡ３",
        .formations = 0x80232888,
        .stages = 0x8023298C,
    },
    {
        AREA(area_kpa),
        .name = "エリア ＫＰＡ",
        .formations = 0x80231A64,
        .stages = 0x80231ED8,
    },
    {
        AREA(area_kpa2),
        .name = "エリア ＫＰＡ２",
        .formations = 0x802346A8,
        .stages = 0x80234720,
    },
    {
        AREA(area_kpa3),
        .name = "エリア ＫＰＡ３",
        .formations = 0x8022839C,
        .stages = 0x802283EC,
    },
    {
        AREA(area_kpa4),
        .name = "エリア ＫＰＡ４",
        .formations = 0x80227910,
        .stages = 0x80227988,
    },
    {
        AREA(area_kkj),
        .name = "エリア ＫＫＪ",
        .formations = 0x802185BC,
        .stages = 0x802185E4,
    },
    {
        AREA(area_dig),
        .name = "エリア ＤＩＧ",
        .formations = 0x8022A7C4,
        .stages = 0x8022A83C,
    },
    {},
    {
        AREA(area_omo2_1),
        .name = "エリア ＯＭＯ２＿１",
    },
    {
        AREA(area_omo2_2),
        .name = "エリア ＯＭＯ２＿２",
    },
    {
        AREA(area_omo2_3),
        .name = "エリア ＯＭＯ２＿３",
    },
    {
        AREA(area_omo2_4),
        .name = "エリア ＯＭＯ２＿４",
    },
    {
        AREA(area_omo2_5),
        .name = "エリア ＯＭＯ２＿５",
    },
    {
        AREA(area_omo2_6),
        .name = "エリア ＯＭＯ２＿６",
    },
    {},
};
