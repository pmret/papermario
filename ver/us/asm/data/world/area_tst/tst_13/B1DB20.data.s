.include "macro.inc"

.section .data

dlabel D_802403C0_B1DB20
.word 0x00000000, 0x00000000, 0x42C80000, 0x42B40000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, D_80242C14_B20374, D_802403C0_B1DB20, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, func_80200000, 0x00000000, 0x00000030, 0x00000001, 0xFE363C80, 0x0000003E, 0x00000002, 0x00000006, 0xFE363C8A, 0x00000031, 0x00000001, 0xFE363C80, 0x00000024, 0x00000002, 0xF4ACD480, 0xFE363C80, 0x00000031, 0x00000001, 0xFE363C80, 0x00000024, 0x00000002, 0xF4ACD481, 0xFE363C80, 0x00000031, 0x00000001, 0xFE363C80, 0x00000024, 0x00000002, 0xF4ACD482, 0xFE363C80, 0x00000031, 0x00000001, 0xFE363C80, 0x00000024, 0x00000002, 0xF4ACD483, 0xFE363C80, 0x00000031, 0x00000001, 0xFE363C80, 0x00000024, 0x00000002, 0xF4ACD484, 0xFE363C80, 0x00000031, 0x00000001, 0xFE363C80, 0x00000024, 0x00000002, 0xF4ACD485, 0xFE363C80, 0x00000024, 0x00000002, 0xFE363C80, 0xFE363C8A, 0x00000047, 0x00000005, D_80240510_B1DC70, 0x00000080, 0xF4ACD480, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240510_B1DC70
.word 0x0000003C, 0x00000001, 0xFE363C80, 0x00000043, 0x00000001, func_80240000_B1D760, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0xF4ACD480, 0x7FFFFE00, 0x00000043, 0x00000003, EnableModel, 0xF4ACD481, 0x00000001, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0xF4ACD480, 0x7FFFFE00, 0x00000043, 0x00000003, EnableModel, 0xF4ACD481, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x0000000B, 0x00000002, 0xF4ACD485, 0x00000000, 0x00000046, 0x00000001, 0xF4ACD485, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240600_B1DD60
.word 0x00000030, 0x00000001, 0xFE363C80, 0x0000003E, 0x00000002, 0x00000006, 0xFE363C89, 0x00000031, 0x00000001, 0xFE363C81, 0x00000024, 0x00000002, 0xF4ACD480, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C81, 0x00000024, 0x00000002, 0xF4ACD481, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C81, 0x00000024, 0x00000002, 0xF4ACD482, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C81, 0x00000024, 0x00000002, 0xF4ACD483, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C81, 0x00000024, 0x00000002, 0xF4ACD484, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C81, 0x00000024, 0x00000002, 0xF4ACD485, 0xFE363C81, 0x00000043, 0x00000003, ParentColliderToModel, 0xF4ACD481, 0xF4ACD480, 0x00000003, 0x00000001, 0x00000000, 0x00000003, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetPlayerActionState, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0x0000000D, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C8A, 0x0000000F, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x0000000B, 0x00000002, 0xFE363C82, 0xF4ACD483, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_802400A0_B1D800, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000046, 0x00000001, D_80240894_B1DFF4, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000002, 0x00000046, 0x00000001, D_80240A58_B1E1B8, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x00000003, 0x00000043, 0x00000002, GetPlayerActionState, 0xFE363C80, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x0000000D, 0x00000004, 0x00000001, 0x00000003, 0x00000013, 0x00000000, 0x0000000A, 0x00000002, 0xFE363C80, 0x0000000F, 0x00000004, 0x00000001, 0x00000003, 0x00000013, 0x00000000, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240894_B1DFF4
.word 0x0000003C, 0x00000001, 0xFE363C89, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000005, 0x00000003, 0x00000001, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xF4ACD480, 0x00000000, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C85, 0xFE363C80, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C82, 0xFE363C85, 0xFE363C84, 0x00000043, 0x00000002, UpdateColliderTransform, 0xF4ACD481, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000005, 0x00000000, 0x00000003, 0x00000001, 0x00000003, 0x00000001, 0x00000003, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xF4ACD480, 0x00000000, 0xFE363C80, 0x00000000, 0x00000024, 0x00000002, 0xFE363C85, 0xFE363C83, 0x00000027, 0x00000002, 0xFE363C85, 0xFE363C80, 0x00000043, 0x00000004, SetPlayerPos, 0xFE363C82, 0xFE363C85, 0xFE363C84, 0x00000043, 0x00000002, UpdateColliderTransform, 0xF4ACD481, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000003, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240A58_B1E1B8
.word 0x0000003C, 0x00000001, 0xFE363C89, 0x00000043, 0x00000007, MakeItemEntity, 0xF4ACD485, 0xF4ACD482, 0xF4ACD483, 0xF4ACD484, 0x00000003, 0x00000000, 0x00000024, 0x00000002, 0xFE363C82, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000000, 0x00000096, 0x00000013, 0x00000004, 0x00000003, 0x00000001, 0x00000002, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xF4ACD480, 0x00000000, 0xFE363C80, 0x00000000, 0x00000027, 0x00000002, 0xFE363C82, 0x0000002D, 0x00000043, 0x00000006, RotateModel, 0xF4ACD480, 0xFE363C82, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000002, 0x00000013, 0x00000000, 0x00000043, 0x00000005, MakeLerp, 0x00000096, 0x00000000, 0x00000013, 0x00000004, 0x00000003, 0x00000001, 0x00000003, 0x00000043, 0x00000001, UpdateLerp, 0x00000043, 0x00000005, TranslateModel, 0xF4ACD480, 0x00000000, 0xFE363C80, 0x00000000, 0x00000027, 0x00000002, 0xFE363C82, 0x0000002D, 0x00000043, 0x00000006, RotateModel, 0xF4ACD480, 0xFE363C82, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C81, 0x00000001, 0x00000004, 0x00000001, 0x00000003, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C08_B1E368
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C18_B1E378
.word 0x00000043, 0x00000003, SetNpcSprite, 0xFFFFFFFF, 0x00030003, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C3C_B1E39C
.word 0x00000043, 0x00000003, SetNpcSprite, 0xFFFFFFFF, 0x00040001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C60_B1E3C0
.word 0x00000043, 0x00000003, SetNpcSprite, 0xFFFFFFFF, 0x00050001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240C84_B1E3E4
.word 0x00000043, 0x00000003, SetNpcSprite, 0xFFFFFFFF, 0x00060001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240CA8_B1E408
.word 0x00000043, 0x00000003, SetNpcSprite, 0xFFFFFFFF, 0x00070001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240CCC_B1E42C
.word 0x00000043, 0x00000003, SetNpcSprite, 0xFFFFFFFF, 0x00080001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240CF0_B1E450
.word 0x00000043, 0x00000003, SetNpcSprite, 0xFFFFFFFF, 0x00080001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240D14_B1E474
.word 0x00000043, 0x00000003, SetNpcSprite, 0xFFFFFFFF, 0x00080001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240D38_B1E498
.word 0x00000043, 0x00000003, SetNpcSprite, 0xFFFFFFFF, 0x00010001, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240D5C_B1E4BC
.word 0x00000043, 0x00000003, SetNpcSprite, 0xFFFFFFFF, 0x00020003, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80240D80_B1E4E0
.word 0x008F0002, 0x00180018, D_80240C08_B1E368, D_80240C18_B1E378, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240DAC_B1E50C
.word 0x008F0002, 0x00180018, D_80240C08_B1E368, D_80240C3C_B1E39C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240DD8_B1E538
.word 0x008F0002, 0x00180018, D_80240C08_B1E368, D_80240C60_B1E3C0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240E04_B1E564
.word 0x008F0002, 0x00180018, D_80240C08_B1E368, D_80240C84_B1E3E4, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240E30_B1E590
.word 0x008F0002, 0x00180018, D_80240C08_B1E368, D_80240CA8_B1E408, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240E5C_B1E5BC
.word 0x008F0002, 0x00180018, D_80240C08_B1E368, D_80240CCC_B1E42C, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240E88_B1E5E8
.word 0x008F0002, 0x00180018, D_80240C08_B1E368, D_80240CF0_B1E450, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240EB4_B1E614
.word 0x008F0002, 0x00180018, D_80240C08_B1E368, D_80240D14_B1E474, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240EE0_B1E640
.word 0x008F0002, 0x00180018, D_80240C08_B1E368, D_80240D38_B1E498, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240F0C_B1E66C
.word 0x008F0002, 0x00180018, D_80240C08_B1E368, D_80240D5C_B1E4BC, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000

dlabel D_80240F38_B1E698
.word 0x00000000, D_80240D80_B1E4E0, 0x00000000, 0x00000000, 0x00000000, 0x00000D09, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80240DAC_B1E50C, 0x41A00000, 0x00000000, 0x41A00000, 0x00000D09, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000002, D_80240DD8_B1E538, 0x42200000, 0x00000000, 0x42200000, 0x00000D09, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, D_80240E04_B1E564, 0x42700000, 0x00000000, 0x42700000, 0x00000D09, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000004, D_80240E30_B1E590, 0x42A00000, 0x00000000, 0x42A00000, 0x00000D09, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000005, D_80240E5C_B1E5BC, 0x42C80000, 0x00000000, 0x42C80000, 0x00000D09, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, D_80240E88_B1E5E8, 0x42F00000, 0x00000000, 0x42F00000, 0x00000D09, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000007, D_80240EB4_B1E614, 0x430C0000, 0x00000000, 0x430C0000, 0x00000D09, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000008, D_80240EE0_B1E640, 0x43200000, 0x00000000, 0x43200000, 0x00000D09, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000009, D_80240F0C_B1E66C, 0x43340000, 0x00000000, 0x43340000, 0x00000D09, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_80242298_B1F9F8
.word 0x0000000A, D_80240F38_B1E698, 0x00000000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802422B0_B1FA10
.word 0x0000000F, 0xFF500000, 0x00000000, 0xFFFFFFFF, 0x0058000F, 0xFF680000, 0x00000000, 0xFFFFFFFF, 0x005A0000, 0xFF640000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFF4C0000, 0x00000000, 0xFFFFFFFF

dlabel D_802422F0_B1FA50
.word 0x0000001A, 0xFF5B0000, 0x00000000, 0xFFFFFFFF, 0x0053001A, 0xFF710000, 0x00000000, 0xFFFFFFFF

dlabel D_80242310_B1FA70
.word 0xFFA8000F, 0xFF680000, 0x00000000, 0xFFFFFFFF

dlabel D_80242320_B1FA80
.word 0xFFA60000, 0xFF640000, 0x00000000, 0xFFFFFFFF, 0xFFAD001A, 0xFF710000, 0x00000000, 0xFFFFFFFF, 0x0098000F, 0xFFA80000, 0x00000000, 0xFFFFFFFF, 0x009C0000, 0xFFA60000, 0x00000000, 0xFFFFFFFF, 0x008F001A, 0xFFAD0000, 0x00000000, 0xFFFFFFFF, 0x00680000, 0xFFC40000, 0x00000000, 0xFFFFFFFF, 0x003C0000, 0xFF980000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFF880000, 0x00000000, 0xFFFFFFFF

dlabel D_802423A0_B1FB00
.word 0xFFC40000, 0xFF980000, 0x00000000, 0xFFFFFFFF, 0x006B000F, 0xFFC20000, 0x00000000, 0xFFFFFFFF, 0x003E000F, 0xFF950000, 0x00000000, 0xFFFFFFFF

dlabel D_802423D0_B1FB30
.word 0x0000000F, 0xFF840000, 0x00000000, 0xFFFFFFFF

dlabel D_802423E0_B1FB40
.word 0xFFC2000F, 0xFF950000, 0x00000000, 0xFFFFFFFF, 0x00780000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x007C000F, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00B40000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0087001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0075001A, 0xFFBC0000, 0x00000000, 0xFFFFFFFF

dlabel D_80242440_B1FBA0
.word 0x0044001A, 0xFF8B0000, 0x00000000, 0xFFFFFFFF, 0x0000001A, 0xFF790000, 0x00000000, 0xFFFFFFFF, 0x0096001E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0082001E, 0xFFB50000, 0x00000000, 0xFFFFFFFF, 0x004B001E, 0xFF7E0000, 0x00000000, 0xFFFFFFFF, 0x0000001E, 0xFF6A0000, 0x00000000, 0xFFFFFFFF

dlabel D_802424A0_B1FC00
.word 0xFFB5001E, 0xFF7E0000, 0x00000000, 0xFFFFFFFF, 0xFFBC001A, 0xFF8B0000, 0x00000000, 0xFFFFFFFF, 0x00A5001A, 0x00000000, 0x00000000, 0xFFFFFFFF

dlabel D_802424D0_B1FC30
.word 0x0075001A, 0x00440000, 0x00000000, 0xFFFFFFFF, 0x006B000F, 0x003E0000, 0x00000000, 0xFFFFFFFF, 0x0082001E, 0x004B0000, 0x00000000, 0xFFFFFFFF, 0x00B0000F, 0x00000000, 0x00000000, 0xFFFFFFFF

dlabel D_80242510_B1FC70
.word 0x009C0000, 0x005A0000, 0x00000000, 0xFFFFFFFF, 0x00680000, 0x003C0000, 0x00000000, 0xFFFFFFFF

dlabel D_80242530_B1FC90
.word 0xFF640000, 0xFFA60000, 0x00000000, 0xFFFFFFFF, 0xFF68000F, 0xFFA80000, 0x00000000, 0xFFFFFFFF, 0xFF980000, 0xFFC40000, 0x00000000, 0xFFFFFFFF, 0xFF50000F, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF5B001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF71001A, 0xFFAD0000, 0x00000000, 0xFFFFFFFF, 0xFF4C0000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF880000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF95000F, 0xFFC20000, 0x00000000, 0xFFFFFFFF, 0xFF84000F, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF8B001A, 0xFFBC0000, 0x00000000, 0xFFFFFFFF, 0xFF79001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF6A001E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF7E001E, 0xFFB50000, 0x00000000, 0xFFFFFFFF

dlabel D_80242610_B1FD70
.word 0x0000000F, 0x00B00000, 0x00000000, 0xFFFFFFFF

dlabel D_80242620_B1FD80
.word 0x005A0000, 0x009C0000, 0x00000000, 0xFFFFFFFF

dlabel D_80242630_B1FD90
.word 0x0058000F, 0x00980000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00B40000, 0x00000000, 0xFFFFFFFF

dlabel D_80242650_B1FDB0
.word 0xFFA8000F, 0x00980000, 0x00000000, 0xFFFFFFFF, 0xFFA60000, 0x009C0000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00780000, 0x00000000, 0xFFFFFFFF, 0xFFC40000, 0x00680000, 0x00000000, 0xFFFFFFFF

dlabel D_80242690_B1FDF0
.word 0x003C0000, 0x00680000, 0x00000000, 0xFFFFFFFF, 0xFF640000, 0x005A0000, 0x00000000, 0xFFFFFFFF, 0xFF980000, 0x003C0000, 0x00000000, 0xFFFFFFFF, 0xFF95000F, 0x003E0000, 0x00000000, 0xFFFFFFFF, 0xFFC2000F, 0x006B0000, 0x00000000, 0xFFFFFFFF

dlabel D_802426E0_B1FE40
.word 0x0000000F, 0x007C0000, 0x00000000, 0xFFFFFFFF, 0xFF8B001A, 0x00440000, 0x00000000, 0xFFFFFFFF, 0xFFBC001A, 0x00750000, 0x00000000, 0xFFFFFFFF

dlabel D_80242710_B1FE70
.word 0x0000001A, 0x00870000, 0x00000000, 0xFFFFFFFF, 0xFF7E001E, 0x004B0000, 0x00000000, 0xFFFFFFFF, 0xFFB5001E, 0x00820000, 0x00000000, 0xFFFFFFFF

dlabel D_80242740_B1FEA0
.word 0x0000001E, 0x00960000, 0x00000000, 0xFFFFFFFF, 0x0000001A, 0x00A50000, 0x00000000, 0xFFFFFFFF, 0x0053001A, 0x008F0000, 0x00000000, 0xFFFFFFFF, 0xFFAD001A, 0x008F0000, 0x00000000, 0xFFFFFFFF

dlabel D_80242780_B1FEE0
.word 0x003E000F, 0x006B0000, 0x00000000, 0xFFFFFFFF, 0x0044001A, 0x00750000, 0x00000000, 0xFFFFFFFF, 0x004B001E, 0x00820000, 0x00000000, 0xFFFFFFFF

dlabel D_802427B0_B1FF10
.word 0xFF71001A, 0x00530000, 0x00000000, 0xFFFFFFFF, 0xFF68000F, 0x00580000, 0x00000000, 0xFFFFFFFF

dlabel D_802427D0_B1FF30
.word 0x0098000F, 0x00580000, 0x00000000, 0xFFFFFFFF, 0x008F001A, 0x00530000, 0x00000000, 0xFFFFFFFF

dlabel D_802427F0_B1FF50
.word 0xFF4C0000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF880000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF84000F, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF79001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF6A001E, 0x00000000, 0x00000000, 0xFFFFFFFF

dlabel D_80242840_B1FFA0
.word 0xFF5B001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0xFF50000F, 0x00000000, 0x00000000, 0xFFFFFFFF

dlabel D_80242860_B1FFC0
.word 0xE7000000, 0x00000000, 0xD9DDFFFF, 0x00000000, 0xD9FFFFFF, 0x00000400, 0x0101E03C, D_802422B0_B1FA10, 0x06000204, 0x00000406, 0x06080A02, 0x00080200, 0x060C0006, 0x000C060E, 0x06100800, 0x0010000C, 0x06021214, 0x00021404, 0x060A1612, 0x000A1202, 0x06041418, 0x0004181A, 0x0606041A, 0x00061A1C, 0x060E061C, 0x000E1C1E, 0x061A1820, 0x001A2022, 0x061C1A22, 0x001C2224, 0x061E1C24, 0x001E2426, 0x0618282A, 0x00182A20, 0x06142C28, 0x00142818, 0x06202A2E, 0x00202E30, 0x06222030, 0x00223032, 0x06242232, 0x00243234, 0x06302E36, 0x00303638, 0x06323038, 0x0032383A, 0x063A3816, 0x003A160A, 0x01002004, D_802422F0_B1FA50, 0x0100500E, D_80242320_B1FA80, 0x01001010, D_802423A0_B1FB00, 0x0100601C, D_802423D0_B1FB30, 0x0101003C, D_80242440_B1FBA0, 0x01002040, D_802427D0_B1FF30, 0x061E1C24, 0x001E2426, 0x06262402, 0x00260200, 0x06282600, 0x00280006, 0x0612101E, 0x00121E2A, 0x062A1E26, 0x002A2628, 0x0622202C, 0x00222C0C, 0x061A2E32, 0x001A3220, 0x0616302E, 0x00162E1A, 0x0620323E, 0x00203E2C, 0x062C3E3C, 0x002C3C34, 0x060C2C34, 0x000C3408, 0x06343C36, 0x00343618, 0x06083418, 0x0008180A, 0x06183638, 0x00183814, 0x06143830, 0x00143016, 0x01003006, D_80242310_B1FA70, 0x01001008, D_802423A0_B1FB00, 0x0100100A, D_802423E0_B1FB40, 0x0100200E, D_802424A0_B1FC00, 0x0101703C, D_80242530_B1FC90, 0x060E0206, 0x000E0612, 0x06100002, 0x0010020E, 0x06120608, 0x0012081E, 0x0614100E, 0x00140E1A, 0x06161810, 0x00161014, 0x06180400, 0x00180010, 0x061A0E12, 0x001A121C, 0x061C121E, 0x001C1E20, 0x061E080C, 0x001E0C22, 0x06201E22, 0x00202224, 0x06220C0A, 0x00220A28, 0x06242228, 0x00242826, 0x06262818, 0x00261816, 0x06280A04, 0x00280418, 0x062A3234, 0x002A3430, 0x062C3036, 0x002C363A, 0x062E2A30, 0x002E302C, 0x06303438, 0x00303836, 0x01001002, D_80242610_B1FD70, 0x01001004, D_80242630_B1FD90, 0x0101402C, D_80242650_B1FDB0, 0x01002030, D_802427B0_B1FF10, 0x0100603C, D_802427F0_B1FF50, 0x06042E0E, 0x00040E06, 0x06060E10, 0x0006100A, 0x06080A14, 0x00081416, 0x060A1012, 0x000A1214, 0x060C0816, 0x000C162A, 0x060E3032, 0x000E3210, 0x06103234, 0x00103412, 0x06123436, 0x00123618, 0x06141218, 0x0014181A, 0x0616141A, 0x00161A1C, 0x06183638, 0x0018381E, 0x061A181E, 0x001A1E20, 0x061C1A20, 0x001C2022, 0x061E383A, 0x001E3A2C, 0x06201E2C, 0x00202C28, 0x06222028, 0x00222824, 0x06242804, 0x00240400, 0x06262400, 0x00260002, 0x06282C2E, 0x00282E04, 0x01003006, D_802424D0_B1FC30, 0x0100200A, D_80242510_B1FC70, 0x0100200E, D_80242620_B1FD80, 0x01002012, D_80242690_B1FDF0, 0x01001014, D_802426E0_B1FE40, 0x01001016, D_80242710_B1FE70, 0x0100301C, D_80242740_B1FEA0, 0x0100802C, D_80242780_B1FEE0, 0x01002030, D_80242840_B1FFA0, 0x061C1214, 0x001C141E, 0x061E1416, 0x001E1620, 0x06201618, 0x0020181A, 0x06222C2E, 0x00222E24, 0x06242E2A, 0x00242A10, 0x06060A0E, 0x00060E08, 0x06260C0A, 0x00260A06, 0x06080E1C, 0x00081C02, 0x06021C1E, 0x00021E00, 0x06001E20, 0x00002004, 0x0604201A, 0x00041A28, 0x06281A0C, 0x00280C26, 0xDF000000, 0x00000000, 0xDF000000, 0x00000000

dlabel D_80242BF8_B20358
.word 0x00000000

dlabel D_80242BFC_B2035C
.word 0x00000005, 0x00000004, 0xFFFFFFDD, 0x00000000, 0xFFFFFFD3, 0x00000156

dlabel D_80242C14_B20374
.word 0x00000024, 0x00000002, 0xF5DE0329, 0x00000017, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, D_80242298_B1F9F8, 0x00000024, 0x00000002, 0xFE363C80, D_80242BFC_B2035C, 0x00000044, 0x00000001, D_80240600_B1DD60, 0x00000043, 0x00000004, SetModelCustomGfx, 0x00000001, 0x00000000, 0xFFFFFFFF, 0x00000043, 0x00000004, SetCustomGfxBuilders, 0x00000000, 0x00000000, func_8024013C_B1D89C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000
