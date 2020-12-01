.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405C8_D13B98
/* D13B98 802405C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D13B9C 802405CC AFBF0010 */  sw        $ra, 0x10($sp)
/* D13BA0 802405D0 8C82000C */  lw        $v0, 0xc($a0)
/* D13BA4 802405D4 0C0B1EAF */  jal       get_variable
/* D13BA8 802405D8 8C450000 */   lw       $a1, ($v0)
/* D13BAC 802405DC 0040182D */  daddu     $v1, $v0, $zero
/* D13BB0 802405E0 10600012 */  beqz      $v1, .L8024062C
/* D13BB4 802405E4 0000202D */   daddu    $a0, $zero, $zero
/* D13BB8 802405E8 8C620000 */  lw        $v0, ($v1)
/* D13BBC 802405EC 5040000A */  beql      $v0, $zero, .L80240618
/* D13BC0 802405F0 00041080 */   sll      $v0, $a0, 2
/* D13BC4 802405F4 3C058024 */  lui       $a1, %hi(D_80245210)
/* D13BC8 802405F8 24A55210 */  addiu     $a1, $a1, %lo(D_80245210)
.L802405FC:
/* D13BCC 802405FC 24630004 */  addiu     $v1, $v1, 4
/* D13BD0 80240600 24840001 */  addiu     $a0, $a0, 1
/* D13BD4 80240604 ACA20000 */  sw        $v0, ($a1)
/* D13BD8 80240608 8C620000 */  lw        $v0, ($v1)
/* D13BDC 8024060C 1440FFFB */  bnez      $v0, .L802405FC
/* D13BE0 80240610 24A50004 */   addiu    $a1, $a1, 4
/* D13BE4 80240614 00041080 */  sll       $v0, $a0, 2
.L80240618:
/* D13BE8 80240618 3C018024 */  lui       $at, %hi(D_80245210)
/* D13BEC 8024061C 00220821 */  addu      $at, $at, $v0
/* D13BF0 80240620 AC205210 */  sw        $zero, %lo(D_80245210)($at)
/* D13BF4 80240624 08090195 */  j         .L80240654
/* D13BF8 80240628 00000000 */   nop      
.L8024062C:
/* D13BFC 8024062C 3C038024 */  lui       $v1, %hi(D_80245210)
/* D13C00 80240630 24635210 */  addiu     $v1, $v1, %lo(D_80245210)
/* D13C04 80240634 0060282D */  daddu     $a1, $v1, $zero
.L80240638:
/* D13C08 80240638 24820010 */  addiu     $v0, $a0, 0x10
/* D13C0C 8024063C AC620000 */  sw        $v0, ($v1)
/* D13C10 80240640 24630004 */  addiu     $v1, $v1, 4
/* D13C14 80240644 24840001 */  addiu     $a0, $a0, 1
/* D13C18 80240648 28820070 */  slti      $v0, $a0, 0x70
/* D13C1C 8024064C 1440FFFA */  bnez      $v0, .L80240638
/* D13C20 80240650 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80240654:
/* D13C24 80240654 8FBF0010 */  lw        $ra, 0x10($sp)
/* D13C28 80240658 24020002 */  addiu     $v0, $zero, 2
/* D13C2C 8024065C 03E00008 */  jr        $ra
/* D13C30 80240660 27BD0018 */   addiu    $sp, $sp, 0x18
