.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242050_95D250
/* 95D250 80242050 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95D254 80242054 AFB10014 */  sw        $s1, 0x14($sp)
/* 95D258 80242058 0080882D */  daddu     $s1, $a0, $zero
/* 95D25C 8024205C AFBF0018 */  sw        $ra, 0x18($sp)
/* 95D260 80242060 AFB00010 */  sw        $s0, 0x10($sp)
/* 95D264 80242064 8E30000C */  lw        $s0, 0xc($s1)
/* 95D268 80242068 8E050000 */  lw        $a1, ($s0)
/* 95D26C 8024206C 0C0B1EAF */  jal       get_variable
/* 95D270 80242070 26100004 */   addiu    $s0, $s0, 4
/* 95D274 80242074 00021880 */  sll       $v1, $v0, 2
/* 95D278 80242078 00621821 */  addu      $v1, $v1, $v0
/* 95D27C 8024207C 00031880 */  sll       $v1, $v1, 2
/* 95D280 80242080 00621823 */  subu      $v1, $v1, $v0
/* 95D284 80242084 000310C0 */  sll       $v0, $v1, 3
/* 95D288 80242088 00621821 */  addu      $v1, $v1, $v0
/* 95D28C 8024208C 000318C0 */  sll       $v1, $v1, 3
/* 95D290 80242090 3C01800B */  lui       $at, 0x800b
/* 95D294 80242094 00230821 */  addu      $at, $at, $v1
/* 95D298 80242098 C4221D98 */  lwc1      $f2, 0x1d98($at)
/* 95D29C 8024209C 3C014480 */  lui       $at, 0x4480
/* 95D2A0 802420A0 44810000 */  mtc1      $at, $f0
/* 95D2A4 802420A4 00000000 */  nop       
/* 95D2A8 802420A8 46001082 */  mul.s     $f2, $f2, $f0
/* 95D2AC 802420AC 00000000 */  nop       
/* 95D2B0 802420B0 3C01CD5B */  lui       $at, 0xcd5b
/* 95D2B4 802420B4 34215858 */  ori       $at, $at, 0x5858
/* 95D2B8 802420B8 44810000 */  mtc1      $at, $f0
/* 95D2BC 802420BC 00000000 */  nop       
/* 95D2C0 802420C0 46001080 */  add.s     $f2, $f2, $f0
/* 95D2C4 802420C4 8E050000 */  lw        $a1, ($s0)
/* 95D2C8 802420C8 4600110D */  trunc.w.s $f4, $f2
/* 95D2CC 802420CC 44062000 */  mfc1      $a2, $f4
/* 95D2D0 802420D0 0C0B2026 */  jal       set_variable
/* 95D2D4 802420D4 0220202D */   daddu    $a0, $s1, $zero
/* 95D2D8 802420D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95D2DC 802420DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 95D2E0 802420E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 95D2E4 802420E4 24020002 */  addiu     $v0, $zero, 2
/* 95D2E8 802420E8 03E00008 */  jr        $ra
/* 95D2EC 802420EC 27BD0020 */   addiu    $sp, $sp, 0x20
