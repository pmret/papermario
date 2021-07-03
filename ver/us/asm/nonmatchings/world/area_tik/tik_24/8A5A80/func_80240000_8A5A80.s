.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242470_8A7EF0
.ascii "tik_18_shape\0\0\0\0"

glabel D_80242480_8A7F00
.ascii "tik_18_hit\0\0tik_25\0\0tik_23\0\0\0\0\0\0"

.section .text

glabel func_80240000_8A5A80
/* 8A5A80 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8A5A84 80240004 3C04800E */  lui       $a0, %hi(D_800D9230)
/* 8A5A88 80240008 24849230 */  addiu     $a0, $a0, %lo(D_800D9230)
/* 8A5A8C 8024000C 3C058024 */  lui       $a1, %hi(D_80242470_8A7EF0)
/* 8A5A90 80240010 24A52470 */  addiu     $a1, $a1, %lo(D_80242470_8A7EF0)
/* 8A5A94 80240014 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8A5A98 80240018 0C01953C */  jal       sprintf
/* 8A5A9C 8024001C 00000000 */   nop
/* 8A5AA0 80240020 3C04800E */  lui       $a0, %hi(D_800D91E0)
/* 8A5AA4 80240024 248491E0 */  addiu     $a0, $a0, %lo(D_800D91E0)
/* 8A5AA8 80240028 3C058024 */  lui       $a1, %hi(D_80242480_8A7F00)
/* 8A5AAC 8024002C 0C01953C */  jal       sprintf
/* 8A5AB0 80240030 24A52480 */   addiu    $a1, $a1, %lo(D_80242480_8A7F00)
/* 8A5AB4 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8A5AB8 80240038 0000102D */  daddu     $v0, $zero, $zero
/* 8A5ABC 8024003C 03E00008 */  jr        $ra
/* 8A5AC0 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8A5AC4 80240044 00000000 */  nop
/* 8A5AC8 80240048 00000000 */  nop
/* 8A5ACC 8024004C 00000000 */  nop
