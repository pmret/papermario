.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405EC_BB765C
/* BB765C 802405EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BB7660 802405F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* BB7664 802405F4 0C046ED4 */  jal       enable_world_fog
/* BB7668 802405F8 00000000 */   nop      
/* BB766C 802405FC 240403C0 */  addiu     $a0, $zero, 0x3c0
/* BB7670 80240600 0C046EDD */  jal       set_world_fog_dist
/* BB7674 80240604 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BB7678 80240608 24040020 */  addiu     $a0, $zero, 0x20
/* BB767C 8024060C 2405001E */  addiu     $a1, $zero, 0x1e
/* BB7680 80240610 2406001C */  addiu     $a2, $zero, 0x1c
/* BB7684 80240614 0C046EE2 */  jal       set_world_fog_color
/* BB7688 80240618 240700FF */   addiu    $a3, $zero, 0xff
/* BB768C 8024061C 0C048BFB */  jal       enable_entity_fog
/* BB7690 80240620 00000000 */   nop      
/* BB7694 80240624 240403DE */  addiu     $a0, $zero, 0x3de
/* BB7698 80240628 0C048C04 */  jal       set_entity_fog_dist
/* BB769C 8024062C 240503E8 */   addiu    $a1, $zero, 0x3e8
/* BB76A0 80240630 0000202D */  daddu     $a0, $zero, $zero
/* BB76A4 80240634 0080282D */  daddu     $a1, $a0, $zero
/* BB76A8 80240638 0080302D */  daddu     $a2, $a0, $zero
/* BB76AC 8024063C 0C048C0A */  jal       set_entity_fog_color
/* BB76B0 80240640 240700FF */   addiu    $a3, $zero, 0xff
/* BB76B4 80240644 3C03800B */  lui       $v1, %hi(gCameras)
/* BB76B8 80240648 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* BB76BC 8024064C 24020018 */  addiu     $v0, $zero, 0x18
/* BB76C0 80240650 A462002C */  sh        $v0, 0x2c($v1)
/* BB76C4 80240654 A462002E */  sh        $v0, 0x2e($v1)
/* BB76C8 80240658 A4620030 */  sh        $v0, 0x30($v1)
/* BB76CC 8024065C 8FBF0010 */  lw        $ra, 0x10($sp)
/* BB76D0 80240660 24020002 */  addiu     $v0, $zero, 2
/* BB76D4 80240664 03E00008 */  jr        $ra
/* BB76D8 80240668 27BD0018 */   addiu    $sp, $sp, 0x18
