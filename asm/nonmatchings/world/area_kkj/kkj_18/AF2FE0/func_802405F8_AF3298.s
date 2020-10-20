.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405F8_AF3298
/* AF3298 802405F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF329C 802405FC AFBF0010 */  sw        $ra, 0x10($sp)
/* AF32A0 80240600 8C82000C */  lw        $v0, 0xc($a0)
/* AF32A4 80240604 0C0B1EAF */  jal       get_variable
/* AF32A8 80240608 8C450000 */   lw       $a1, ($v0)
/* AF32AC 8024060C 0040182D */  daddu     $v1, $v0, $zero
/* AF32B0 80240610 10600012 */  beqz      $v1, .L8024065C
/* AF32B4 80240614 0000202D */   daddu    $a0, $zero, $zero
/* AF32B8 80240618 8C620000 */  lw        $v0, ($v1)
/* AF32BC 8024061C 5040000A */  beql      $v0, $zero, .L80240648
/* AF32C0 80240620 00041080 */   sll      $v0, $a0, 2
/* AF32C4 80240624 3C058024 */  lui       $a1, 0x8024
/* AF32C8 80240628 24A54CB0 */  addiu     $a1, $a1, 0x4cb0
.L8024062C:
/* AF32CC 8024062C 24630004 */  addiu     $v1, $v1, 4
/* AF32D0 80240630 24840001 */  addiu     $a0, $a0, 1
/* AF32D4 80240634 ACA20000 */  sw        $v0, ($a1)
/* AF32D8 80240638 8C620000 */  lw        $v0, ($v1)
/* AF32DC 8024063C 1440FFFB */  bnez      $v0, .L8024062C
/* AF32E0 80240640 24A50004 */   addiu    $a1, $a1, 4
/* AF32E4 80240644 00041080 */  sll       $v0, $a0, 2
.L80240648:
/* AF32E8 80240648 3C018024 */  lui       $at, 0x8024
/* AF32EC 8024064C 00220821 */  addu      $at, $at, $v0
/* AF32F0 80240650 AC204CB0 */  sw        $zero, 0x4cb0($at)
/* AF32F4 80240654 080901A1 */  j         .L80240684
/* AF32F8 80240658 00000000 */   nop      
.L8024065C:
/* AF32FC 8024065C 3C038024 */  lui       $v1, 0x8024
/* AF3300 80240660 24634CB0 */  addiu     $v1, $v1, 0x4cb0
/* AF3304 80240664 0060282D */  daddu     $a1, $v1, $zero
.L80240668:
/* AF3308 80240668 24820010 */  addiu     $v0, $a0, 0x10
/* AF330C 8024066C AC620000 */  sw        $v0, ($v1)
/* AF3310 80240670 24630004 */  addiu     $v1, $v1, 4
/* AF3314 80240674 24840001 */  addiu     $a0, $a0, 1
/* AF3318 80240678 28820070 */  slti      $v0, $a0, 0x70
/* AF331C 8024067C 1440FFFA */  bnez      $v0, .L80240668
/* AF3320 80240680 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80240684:
/* AF3324 80240684 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF3328 80240688 24020002 */  addiu     $v0, $zero, 2
/* AF332C 8024068C 03E00008 */  jr        $ra
/* AF3330 80240690 27BD0018 */   addiu    $sp, $sp, 0x18
