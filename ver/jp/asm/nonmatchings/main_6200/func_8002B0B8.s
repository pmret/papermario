.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B0B8
/* 64B8 8002B0B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 64BC 8002B0BC AFB00010 */  sw        $s0, 0x10($sp)
/* 64C0 8002B0C0 3C058007 */  lui       $a1, %hi(D_800745B0)
/* 64C4 8002B0C4 24A545B0 */  addiu     $a1, $a1, %lo(D_800745B0)
/* 64C8 8002B0C8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 64CC 8002B0CC 0C01BB54 */  jal       func_8006ED50
/* 64D0 8002B0D0 0080802D */   daddu    $s0, $a0, $zero
/* 64D4 8002B0D4 1440000B */  bnez      $v0, .L8002B104
/* 64D8 8002B0D8 0000102D */   daddu    $v0, $zero, $zero
/* 64DC 8002B0DC 8E020034 */  lw        $v0, 0x34($s0)
/* 64E0 8002B0E0 8E030030 */  lw        $v1, 0x30($s0)
/* 64E4 8002B0E4 00021027 */  nor       $v0, $zero, $v0
/* 64E8 8002B0E8 54620006 */  bnel      $v1, $v0, .L8002B104
/* 64EC 8002B0EC 0000102D */   daddu    $v0, $zero, $zero
/* 64F0 8002B0F0 0C00AC24 */  jal       func_8002B090
/* 64F4 8002B0F4 0200202D */   daddu    $a0, $s0, $zero
/* 64F8 8002B0F8 8E030030 */  lw        $v1, 0x30($s0)
/* 64FC 8002B0FC 00431026 */  xor       $v0, $v0, $v1
/* 6500 8002B100 2C420001 */  sltiu     $v0, $v0, 1
.L8002B104:
/* 6504 8002B104 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6508 8002B108 8FB00010 */  lw        $s0, 0x10($sp)
/* 650C 8002B10C 03E00008 */  jr        $ra
/* 6510 8002B110 27BD0018 */   addiu    $sp, $sp, 0x18
