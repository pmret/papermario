.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405BC
/* 8EC3DC 802405BC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 8EC3E0 802405C0 AFB30044 */  sw        $s3, 0x44($sp)
/* 8EC3E4 802405C4 3C138026 */  lui       $s3, 0x8026
/* 8EC3E8 802405C8 2673B2AC */  addiu     $s3, $s3, -0x4d54
/* 8EC3EC 802405CC AFBF0048 */  sw        $ra, 0x48($sp)
/* 8EC3F0 802405D0 AFB20040 */  sw        $s2, 0x40($sp)
/* 8EC3F4 802405D4 AFB1003C */  sw        $s1, 0x3c($sp)
/* 8EC3F8 802405D8 AFB00038 */  sw        $s0, 0x38($sp)
/* 8EC3FC 802405DC 8E620000 */  lw        $v0, ($s3)
/* 8EC400 802405E0 24420014 */  addiu     $v0, $v0, 0x14
/* 8EC404 802405E4 AE620000 */  sw        $v0, ($s3)
/* 8EC408 802405E8 28420100 */  slti      $v0, $v0, 0x100
/* 8EC40C 802405EC 14400002 */  bnez      $v0, .L802405F8
/* 8EC410 802405F0 240200FF */   addiu    $v0, $zero, 0xff
/* 8EC414 802405F4 AE620000 */  sw        $v0, ($s3)
.L802405F8:
/* 8EC418 802405F8 3C108026 */  lui       $s0, 0x8026
/* 8EC41C 802405FC 2610B2B0 */  addiu     $s0, $s0, -0x4d50
/* 8EC420 80240600 8E040000 */  lw        $a0, ($s0)
/* 8EC424 80240604 8E07000C */  lw        $a3, 0xc($s0)
/* 8EC428 80240608 24020055 */  addiu     $v0, $zero, 0x55
/* 8EC42C 8024060C AFA20018 */  sw        $v0, 0x18($sp)
/* 8EC430 80240610 24020061 */  addiu     $v0, $zero, 0x61
/* 8EC434 80240614 24120140 */  addiu     $s2, $zero, 0x140
/* 8EC438 80240618 AFA2001C */  sw        $v0, 0x1c($sp)
/* 8EC43C 8024061C AFA00020 */  sw        $zero, 0x20($sp)
/* 8EC440 80240620 AFA00024 */  sw        $zero, 0x24($sp)
/* 8EC444 80240624 AFB20028 */  sw        $s2, 0x28($sp)
/* 8EC448 80240628 96050008 */  lhu       $a1, 8($s0)
/* 8EC44C 8024062C 241100F0 */  addiu     $s1, $zero, 0xf0
/* 8EC450 80240630 AFB1002C */  sw        $s1, 0x2c($sp)
/* 8EC454 80240634 8E020010 */  lw        $v0, 0x10($s0)
/* 8EC458 80240638 9606000A */  lhu       $a2, 0xa($s0)
/* 8EC45C 8024063C 8E030004 */  lw        $v1, 4($s0)
/* 8EC460 80240640 92680003 */  lbu       $t0, 3($s3)
/* 8EC464 80240644 AFA20010 */  sw        $v0, 0x10($sp)
/* 8EC468 80240648 AFA30014 */  sw        $v1, 0x14($sp)
/* 8EC46C 8024064C 0C04BA68 */  jal       func_8012E9A0
/* 8EC470 80240650 AFA80030 */   sw       $t0, 0x30($sp)
/* 8EC474 80240654 8E040014 */  lw        $a0, 0x14($s0)
/* 8EC478 80240658 8E070020 */  lw        $a3, 0x20($s0)
/* 8EC47C 8024065C 240200A0 */  addiu     $v0, $zero, 0xa0
/* 8EC480 80240660 AFA20018 */  sw        $v0, 0x18($sp)
/* 8EC484 80240664 9605001C */  lhu       $a1, 0x1c($s0)
/* 8EC488 80240668 24020066 */  addiu     $v0, $zero, 0x66
/* 8EC48C 8024066C AFA2001C */  sw        $v0, 0x1c($sp)
/* 8EC490 80240670 AFA00020 */  sw        $zero, 0x20($sp)
/* 8EC494 80240674 AFA00024 */  sw        $zero, 0x24($sp)
/* 8EC498 80240678 AFB20028 */  sw        $s2, 0x28($sp)
/* 8EC49C 8024067C AFB1002C */  sw        $s1, 0x2c($sp)
/* 8EC4A0 80240680 8E020024 */  lw        $v0, 0x24($s0)
/* 8EC4A4 80240684 9606001E */  lhu       $a2, 0x1e($s0)
/* 8EC4A8 80240688 8E030018 */  lw        $v1, 0x18($s0)
/* 8EC4AC 8024068C 92680003 */  lbu       $t0, 3($s3)
/* 8EC4B0 80240690 AFA20010 */  sw        $v0, 0x10($sp)
/* 8EC4B4 80240694 AFA30014 */  sw        $v1, 0x14($sp)
/* 8EC4B8 80240698 0C04BA68 */  jal       func_8012E9A0
/* 8EC4BC 8024069C AFA80030 */   sw       $t0, 0x30($sp)
/* 8EC4C0 802406A0 8FBF0048 */  lw        $ra, 0x48($sp)
/* 8EC4C4 802406A4 8FB30044 */  lw        $s3, 0x44($sp)
/* 8EC4C8 802406A8 8FB20040 */  lw        $s2, 0x40($sp)
/* 8EC4CC 802406AC 8FB1003C */  lw        $s1, 0x3c($sp)
/* 8EC4D0 802406B0 8FB00038 */  lw        $s0, 0x38($sp)
/* 8EC4D4 802406B4 03E00008 */  jr        $ra
/* 8EC4D8 802406B8 27BD0050 */   addiu    $sp, $sp, 0x50
