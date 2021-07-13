.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_battle_section
/* 4DFDC 80072BDC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4DFE0 80072BE0 3C02800E */  lui       $v0, %hi(gBattleStatus+0x47A)
/* 4DFE4 80072BE4 9042C4EA */  lbu       $v0, %lo(gBattleStatus+0x47A)($v0)
/* 4DFE8 80072BE8 3C038009 */  lui       $v1, %hi(gBattleAreas)
/* 4DFEC 80072BEC 24635A30 */  addiu     $v1, $v1, %lo(gBattleAreas)
/* 4DFF0 80072BF0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4DFF4 80072BF4 AFB10014 */  sw        $s1, 0x14($sp)
/* 4DFF8 80072BF8 AFB00010 */  sw        $s0, 0x10($sp)
/* 4DFFC 80072BFC 00021140 */  sll       $v0, $v0, 5
/* 4E000 80072C00 00438821 */  addu      $s1, $v0, $v1
/* 4E004 80072C04 8E240004 */  lw        $a0, 4($s1)
/* 4E008 80072C08 8E250008 */  lw        $a1, 8($s1)
/* 4E00C 80072C0C 8E26000C */  lw        $a2, 0xc($s1)
/* 4E010 80072C10 3C10800E */  lui       $s0, %hi(gBattleStatus+0x47B)
/* 4E014 80072C14 9210C4EB */  lbu       $s0, %lo(gBattleStatus+0x47B)($s0)
/* 4E018 80072C18 0C00A5CF */  jal       dma_copy
/* 4E01C 80072C1C 00000000 */   nop
/* 4E020 80072C20 00101880 */  sll       $v1, $s0, 2
/* 4E024 80072C24 00701821 */  addu      $v1, $v1, $s0
/* 4E028 80072C28 00031880 */  sll       $v1, $v1, 2
/* 4E02C 80072C2C 8E220010 */  lw        $v0, 0x10($s1)
/* 4E030 80072C30 3C04800E */  lui       $a0, %hi(gBattleStatus+0x47C)
/* 4E034 80072C34 8C84C4EC */  lw        $a0, %lo(gBattleStatus+0x47C)($a0)
/* 4E038 80072C38 00431021 */  addu      $v0, $v0, $v1
/* 4E03C 80072C3C 3C01800E */  lui       $at, %hi(gBattleStatus+0x48C)
/* 4E040 80072C40 AC22C4FC */  sw        $v0, %lo(gBattleStatus+0x48C)($at)
/* 4E044 80072C44 04810005 */  bgez      $a0, .L80072C5C
/* 4E048 80072C48 000418C0 */   sll      $v1, $a0, 3
/* 4E04C 80072C4C 3C01800E */  lui       $at, %hi(D_800DC064)
/* 4E050 80072C50 AC20C064 */  sw        $zero, %lo(D_800DC064)($at)
/* 4E054 80072C54 0801CB1B */  j         .L80072C6C
/* 4E058 80072C58 00000000 */   nop
.L80072C5C:
/* 4E05C 80072C5C 8E220014 */  lw        $v0, 0x14($s1)
/* 4E060 80072C60 00431021 */  addu      $v0, $v0, $v1
/* 4E064 80072C64 3C01800E */  lui       $at, %hi(D_800DC064)
/* 4E068 80072C68 AC22C064 */  sw        $v0, %lo(D_800DC064)($at)
.L80072C6C:
/* 4E06C 80072C6C 0C090464 */  jal       btl_set_state
/* 4E070 80072C70 24040001 */   addiu    $a0, $zero, 1
/* 4E074 80072C74 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4E078 80072C78 8FB10014 */  lw        $s1, 0x14($sp)
/* 4E07C 80072C7C 8FB00010 */  lw        $s0, 0x10($sp)
/* 4E080 80072C80 3C01800E */  lui       $at, %hi(gBattleStatus+0x460)
/* 4E084 80072C84 AC20C4D0 */  sw        $zero, %lo(gBattleStatus+0x460)($at)
/* 4E088 80072C88 03E00008 */  jr        $ra
/* 4E08C 80072C8C 27BD0020 */   addiu    $sp, $sp, 0x20
