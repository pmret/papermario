.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405FC_BED3EC
/* BED3EC 802405FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BED3F0 80240600 AFB20020 */  sw        $s2, 0x20($sp)
/* BED3F4 80240604 0080902D */  daddu     $s2, $a0, $zero
/* BED3F8 80240608 AFBF0024 */  sw        $ra, 0x24($sp)
/* BED3FC 8024060C AFB1001C */  sw        $s1, 0x1c($sp)
/* BED400 80240610 AFB00018 */  sw        $s0, 0x18($sp)
/* BED404 80240614 10A00035 */  beqz      $a1, .L802406EC
/* BED408 80240618 8E51000C */   lw       $s1, 0xc($s2)
/* BED40C 8024061C 0C00AB39 */  jal       heap_malloc
/* BED410 80240620 24040058 */   addiu    $a0, $zero, 0x58
/* BED414 80240624 0040802D */  daddu     $s0, $v0, $zero
/* BED418 80240628 AE500084 */  sw        $s0, 0x84($s2)
/* BED41C 8024062C 8E250000 */  lw        $a1, ($s1)
/* BED420 80240630 26310004 */  addiu     $s1, $s1, 4
/* BED424 80240634 0C0B1EAF */  jal       get_variable
/* BED428 80240638 0240202D */   daddu    $a0, $s2, $zero
/* BED42C 8024063C AE020038 */  sw        $v0, 0x38($s0)
/* BED430 80240640 8E250000 */  lw        $a1, ($s1)
/* BED434 80240644 26310004 */  addiu     $s1, $s1, 4
/* BED438 80240648 0C0B210B */  jal       get_float_variable
/* BED43C 8024064C 0240202D */   daddu    $a0, $s2, $zero
/* BED440 80240650 E6000018 */  swc1      $f0, 0x18($s0)
/* BED444 80240654 8E250000 */  lw        $a1, ($s1)
/* BED448 80240658 26310004 */  addiu     $s1, $s1, 4
/* BED44C 8024065C 0C0B210B */  jal       get_float_variable
/* BED450 80240660 0240202D */   daddu    $a0, $s2, $zero
/* BED454 80240664 E6000024 */  swc1      $f0, 0x24($s0)
/* BED458 80240668 8E250000 */  lw        $a1, ($s1)
/* BED45C 8024066C 26310004 */  addiu     $s1, $s1, 4
/* BED460 80240670 0C0B210B */  jal       get_float_variable
/* BED464 80240674 0240202D */   daddu    $a0, $s2, $zero
/* BED468 80240678 E6000020 */  swc1      $f0, 0x20($s0)
/* BED46C 8024067C 8E250000 */  lw        $a1, ($s1)
/* BED470 80240680 0C0B210B */  jal       get_float_variable
/* BED474 80240684 0240202D */   daddu    $a0, $s2, $zero
/* BED478 80240688 3C013F80 */  lui       $at, 0x3f80
/* BED47C 8024068C 44811000 */  mtc1      $at, $f2
/* BED480 80240690 E6000028 */  swc1      $f0, 0x28($s0)
/* BED484 80240694 AFA00014 */  sw        $zero, 0x14($sp)
/* BED488 80240698 E7A20010 */  swc1      $f2, 0x10($sp)
/* BED48C 8024069C 8E050018 */  lw        $a1, 0x18($s0)
/* BED490 802406A0 8E060024 */  lw        $a2, 0x24($s0)
/* BED494 802406A4 8E070020 */  lw        $a3, 0x20($s0)
/* BED498 802406A8 0C01C9AC */  jal       func_800726B0
/* BED49C 802406AC 24040001 */   addiu    $a0, $zero, 1
/* BED4A0 802406B0 AE020054 */  sw        $v0, 0x54($s0)
/* BED4A4 802406B4 8C43000C */  lw        $v1, 0xc($v0)
/* BED4A8 802406B8 9202003B */  lbu       $v0, 0x3b($s0)
/* BED4AC 802406BC A0620034 */  sb        $v0, 0x34($v1)
/* BED4B0 802406C0 8E020054 */  lw        $v0, 0x54($s0)
/* BED4B4 802406C4 8C42000C */  lw        $v0, 0xc($v0)
/* BED4B8 802406C8 AC400020 */  sw        $zero, 0x20($v0)
/* BED4BC 802406CC 8E050018 */  lw        $a1, 0x18($s0)
/* BED4C0 802406D0 8E060028 */  lw        $a2, 0x28($s0)
/* BED4C4 802406D4 8E070020 */  lw        $a3, 0x20($s0)
/* BED4C8 802406D8 0C044898 */  jal       create_shadow_type
/* BED4CC 802406DC 0000202D */   daddu    $a0, $zero, $zero
/* BED4D0 802406E0 AE020040 */  sw        $v0, 0x40($s0)
/* BED4D4 802406E4 2402010E */  addiu     $v0, $zero, 0x10e
/* BED4D8 802406E8 A602004C */  sh        $v0, 0x4c($s0)
.L802406EC:
/* BED4DC 802406EC 8FBF0024 */  lw        $ra, 0x24($sp)
/* BED4E0 802406F0 8FB20020 */  lw        $s2, 0x20($sp)
/* BED4E4 802406F4 8FB1001C */  lw        $s1, 0x1c($sp)
/* BED4E8 802406F8 8FB00018 */  lw        $s0, 0x18($sp)
/* BED4EC 802406FC 24020002 */  addiu     $v0, $zero, 2
/* BED4F0 80240700 03E00008 */  jr        $ra
/* BED4F4 80240704 27BD0028 */   addiu    $sp, $sp, 0x28
