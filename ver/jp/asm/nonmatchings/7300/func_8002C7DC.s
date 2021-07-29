.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C7DC
/* 7BDC 8002C7DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7BE0 8002C7E0 2404000A */  addiu     $a0, $zero, 0xa
/* 7BE4 8002C7E4 AFB00018 */  sw        $s0, 0x18($sp)
/* 7BE8 8002C7E8 3C10800A */  lui       $s0, %hi(D_8009C4C0)
/* 7BEC 8002C7EC 2610C4C0 */  addiu     $s0, $s0, %lo(D_8009C4C0)
/* 7BF0 8002C7F0 0200282D */  daddu     $a1, $s0, $zero
/* 7BF4 8002C7F4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7BF8 8002C7F8 0C019648 */  jal       func_80065920
/* 7BFC 8002C7FC 24060001 */   addiu    $a2, $zero, 1
/* 7C00 8002C800 2404000C */  addiu     $a0, $zero, 0xc
/* 7C04 8002C804 0200282D */  daddu     $a1, $s0, $zero
/* 7C08 8002C808 0C019648 */  jal       func_80065920
/* 7C0C 8002C80C 24060002 */   addiu    $a2, $zero, 2
.L8002C810:
/* 7C10 8002C810 3C04800A */  lui       $a0, %hi(D_8009C4C0)
/* 7C14 8002C814 2484C4C0 */  addiu     $a0, $a0, %lo(D_8009C4C0)
/* 7C18 8002C818 27A50010 */  addiu     $a1, $sp, 0x10
/* 7C1C 8002C81C 0C0195B0 */  jal       func_800656C0
/* 7C20 8002C820 24060001 */   addiu    $a2, $zero, 1
/* 7C24 8002C824 0C00B1DC */  jal       func_8002C770
/* 7C28 8002C828 00000000 */   nop
/* 7C2C 8002C82C 0040802D */  daddu     $s0, $v0, $zero
/* 7C30 8002C830 1200FFF7 */  beqz      $s0, .L8002C810
/* 7C34 8002C834 00000000 */   nop
/* 7C38 8002C838 0C019844 */  jal       func_80066110
/* 7C3C 8002C83C 0200202D */   daddu    $a0, $s0, $zero
/* 7C40 8002C840 0C00B0DC */  jal       func_8002C370
/* 7C44 8002C844 0200202D */   daddu    $a0, $s0, $zero
.L8002C848:
/* 7C48 8002C848 0800B212 */  j         .L8002C848
/* 7C4C 8002C84C 00000000 */   nop
