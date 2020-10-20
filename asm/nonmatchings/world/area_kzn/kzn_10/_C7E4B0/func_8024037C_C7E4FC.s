.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024037C_C7E4FC
/* C7E4FC 8024037C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C7E500 80240380 AFB00028 */  sw        $s0, 0x28($sp)
/* C7E504 80240384 0080802D */  daddu     $s0, $a0, $zero
/* C7E508 80240388 AFBF002C */  sw        $ra, 0x2c($sp)
/* C7E50C 8024038C C6000084 */  lwc1      $f0, 0x84($s0)
/* C7E510 80240390 46800020 */  cvt.s.w   $f0, $f0
/* C7E514 80240394 E7A00018 */  swc1      $f0, 0x18($sp)
/* C7E518 80240398 C600008C */  lwc1      $f0, 0x8c($s0)
/* C7E51C 8024039C 46800020 */  cvt.s.w   $f0, $f0
/* C7E520 802403A0 27A20024 */  addiu     $v0, $sp, 0x24
/* C7E524 802403A4 3C040001 */  lui       $a0, 1
/* C7E528 802403A8 27A50018 */  addiu     $a1, $sp, 0x18
/* C7E52C 802403AC 27A6001C */  addiu     $a2, $sp, 0x1c
/* C7E530 802403B0 3C0144FA */  lui       $at, 0x44fa
/* C7E534 802403B4 44811000 */  mtc1      $at, $f2
/* C7E538 802403B8 27A70020 */  addiu     $a3, $sp, 0x20
/* C7E53C 802403BC E7A0001C */  swc1      $f0, 0x1c($sp)
/* C7E540 802403C0 AFA00020 */  sw        $zero, 0x20($sp)
/* C7E544 802403C4 E7A20024 */  swc1      $f2, 0x24($sp)
/* C7E548 802403C8 0C0372DF */  jal       func_800DCB7C
/* C7E54C 802403CC AFA20010 */   sw       $v0, 0x10($sp)
/* C7E550 802403D0 1040000B */  beqz      $v0, .L80240400
/* C7E554 802403D4 00000000 */   nop      
/* C7E558 802403D8 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* C7E55C 802403DC 3C01425C */  lui       $at, 0x425c
/* C7E560 802403E0 44810000 */  mtc1      $at, $f0
/* C7E564 802403E4 00000000 */  nop       
/* C7E568 802403E8 46001080 */  add.s     $f2, $f2, $f0
/* C7E56C 802403EC C7A00018 */  lwc1      $f0, 0x18($sp)
/* C7E570 802403F0 4600010D */  trunc.w.s $f4, $f0
/* C7E574 802403F4 E6040084 */  swc1      $f4, 0x84($s0)
/* C7E578 802403F8 4600110D */  trunc.w.s $f4, $f2
/* C7E57C 802403FC E604008C */  swc1      $f4, 0x8c($s0)
.L80240400:
/* C7E580 80240400 8FBF002C */  lw        $ra, 0x2c($sp)
/* C7E584 80240404 8FB00028 */  lw        $s0, 0x28($sp)
/* C7E588 80240408 24020002 */  addiu     $v0, $zero, 2
/* C7E58C 8024040C 03E00008 */  jr        $ra
/* C7E590 80240410 27BD0030 */   addiu    $sp, $sp, 0x30
