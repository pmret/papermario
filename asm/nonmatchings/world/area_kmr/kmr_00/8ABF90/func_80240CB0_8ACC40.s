.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CB0_8ACC40
/* 8ACC40 80240CB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8ACC44 80240CB4 AFB10014 */  sw        $s1, 0x14($sp)
/* 8ACC48 80240CB8 0080882D */  daddu     $s1, $a0, $zero
/* 8ACC4C 80240CBC AFBF0018 */  sw        $ra, 0x18($sp)
/* 8ACC50 80240CC0 10A0000C */  beqz      $a1, .L80240CF4
/* 8ACC54 80240CC4 AFB00010 */   sw       $s0, 0x10($sp)
/* 8ACC58 80240CC8 8E24014C */  lw        $a0, 0x14c($s1)
/* 8ACC5C 80240CCC 0C00EAD2 */  jal       get_npc_safe
/* 8ACC60 80240CD0 AE200074 */   sw       $zero, 0x74($s1)
/* 8ACC64 80240CD4 8E23014C */  lw        $v1, 0x14c($s1)
/* 8ACC68 80240CD8 AE220078 */  sw        $v0, 0x78($s1)
/* 8ACC6C 80240CDC 2463FFFF */  addiu     $v1, $v1, -1
/* 8ACC70 80240CE0 00031840 */  sll       $v1, $v1, 1
/* 8ACC74 80240CE4 3C028024 */  lui       $v0, 0x8024
/* 8ACC78 80240CE8 00431021 */  addu      $v0, $v0, $v1
/* 8ACC7C 80240CEC 84422D60 */  lh        $v0, 0x2d60($v0)
/* 8ACC80 80240CF0 AE22007C */  sw        $v0, 0x7c($s1)
.L80240CF4:
/* 8ACC84 80240CF4 8E22007C */  lw        $v0, 0x7c($s1)
/* 8ACC88 80240CF8 14400015 */  bnez      $v0, .L80240D50
/* 8ACC8C 80240CFC 2442FFFF */   addiu    $v0, $v0, -1
/* 8ACC90 80240D00 C62C0074 */  lwc1      $f12, 0x74($s1)
/* 8ACC94 80240D04 0C00A8BB */  jal       sin_deg
/* 8ACC98 80240D08 8E300078 */   lw       $s0, 0x78($s1)
/* 8ACC9C 80240D0C 3C013FC0 */  lui       $at, 0x3fc0
/* 8ACCA0 80240D10 44811000 */  mtc1      $at, $f2
/* 8ACCA4 80240D14 00000000 */  nop       
/* 8ACCA8 80240D18 46020002 */  mul.s     $f0, $f0, $f2
/* 8ACCAC 80240D1C 00000000 */  nop       
/* 8ACCB0 80240D20 3C014190 */  lui       $at, 0x4190
/* 8ACCB4 80240D24 44816000 */  mtc1      $at, $f12
/* 8ACCB8 80240D28 4600010D */  trunc.w.s $f4, $f0
/* 8ACCBC 80240D2C 44022000 */  mfc1      $v0, $f4
/* 8ACCC0 80240D30 00000000 */  nop       
/* 8ACCC4 80240D34 A20200AB */  sb        $v0, 0xab($s0)
/* 8ACCC8 80240D38 C6200074 */  lwc1      $f0, 0x74($s1)
/* 8ACCCC 80240D3C 0C00A6C9 */  jal       clamp_angle
/* 8ACCD0 80240D40 460C0300 */   add.s    $f12, $f0, $f12
/* 8ACCD4 80240D44 0000102D */  daddu     $v0, $zero, $zero
/* 8ACCD8 80240D48 08090356 */  j         .L80240D58
/* 8ACCDC 80240D4C E6200074 */   swc1     $f0, 0x74($s1)
.L80240D50:
/* 8ACCE0 80240D50 AE22007C */  sw        $v0, 0x7c($s1)
/* 8ACCE4 80240D54 0000102D */  daddu     $v0, $zero, $zero
.L80240D58:
/* 8ACCE8 80240D58 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8ACCEC 80240D5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8ACCF0 80240D60 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ACCF4 80240D64 03E00008 */  jr        $ra
/* 8ACCF8 80240D68 27BD0020 */   addiu    $sp, $sp, 0x20
/* 8ACCFC 80240D6C 00000000 */  nop       
