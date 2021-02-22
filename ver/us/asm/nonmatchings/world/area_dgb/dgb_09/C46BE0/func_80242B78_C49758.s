.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B78_C49758
/* C49758 80242B78 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C4975C 80242B7C AFB20020 */  sw        $s2, 0x20($sp)
/* C49760 80242B80 0080902D */  daddu     $s2, $a0, $zero
/* C49764 80242B84 AFBF0024 */  sw        $ra, 0x24($sp)
/* C49768 80242B88 AFB1001C */  sw        $s1, 0x1c($sp)
/* C4976C 80242B8C AFB00018 */  sw        $s0, 0x18($sp)
/* C49770 80242B90 8E500148 */  lw        $s0, 0x148($s2)
/* C49774 80242B94 0C00EABB */  jal       get_npc_unsafe
/* C49778 80242B98 86040008 */   lh       $a0, 8($s0)
/* C4977C 80242B9C 0040882D */  daddu     $s1, $v0, $zero
/* C49780 80242BA0 8E02006C */  lw        $v0, 0x6c($s0)
/* C49784 80242BA4 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* C49788 80242BA8 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* C4978C 80242BAC 34420100 */  ori       $v0, $v0, 0x100
/* C49790 80242BB0 AE02006C */  sw        $v0, 0x6c($s0)
/* C49794 80242BB4 C4600028 */  lwc1      $f0, 0x28($v1)
/* C49798 80242BB8 E6200038 */  swc1      $f0, 0x38($s1)
/* C4979C 80242BBC C4600030 */  lwc1      $f0, 0x30($v1)
/* C497A0 80242BC0 E6200040 */  swc1      $f0, 0x40($s1)
/* C497A4 80242BC4 8E03006C */  lw        $v1, 0x6c($s0)
/* C497A8 80242BC8 30621000 */  andi      $v0, $v1, 0x1000
/* C497AC 80242BCC 14400003 */  bnez      $v0, .L80242BDC
/* C497B0 80242BD0 3C048000 */   lui      $a0, 0x8000
/* C497B4 80242BD4 34621000 */  ori       $v0, $v1, 0x1000
/* C497B8 80242BD8 AE02006C */  sw        $v0, 0x6c($s0)
.L80242BDC:
/* C497BC 80242BDC C6200040 */  lwc1      $f0, 0x40($s1)
/* C497C0 80242BE0 34840011 */  ori       $a0, $a0, 0x11
/* C497C4 80242BE4 E7A00010 */  swc1      $f0, 0x10($sp)
/* C497C8 80242BE8 8E260038 */  lw        $a2, 0x38($s1)
/* C497CC 80242BEC 8E27003C */  lw        $a3, 0x3c($s1)
/* C497D0 80242BF0 0C052757 */  jal       play_sound_at_position
/* C497D4 80242BF4 24050002 */   addiu    $a1, $zero, 2
/* C497D8 80242BF8 2402000F */  addiu     $v0, $zero, 0xf
/* C497DC 80242BFC A620008E */  sh        $zero, 0x8e($s1)
/* C497E0 80242C00 AE420070 */  sw        $v0, 0x70($s2)
/* C497E4 80242C04 8FBF0024 */  lw        $ra, 0x24($sp)
/* C497E8 80242C08 8FB20020 */  lw        $s2, 0x20($sp)
/* C497EC 80242C0C 8FB1001C */  lw        $s1, 0x1c($sp)
/* C497F0 80242C10 8FB00018 */  lw        $s0, 0x18($sp)
/* C497F4 80242C14 03E00008 */  jr        $ra
/* C497F8 80242C18 27BD0028 */   addiu    $sp, $sp, 0x28
