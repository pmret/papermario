.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240120_CAEE60
/* CAEE60 80240120 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CAEE64 80240124 AFB3001C */  sw        $s3, 0x1c($sp)
/* CAEE68 80240128 0080982D */  daddu     $s3, $a0, $zero
/* CAEE6C 8024012C AFB00010 */  sw        $s0, 0x10($sp)
/* CAEE70 80240130 24100001 */  addiu     $s0, $zero, 1
/* CAEE74 80240134 AFB40020 */  sw        $s4, 0x20($sp)
/* CAEE78 80240138 2414FFFF */  addiu     $s4, $zero, -1
/* CAEE7C 8024013C AFB50024 */  sw        $s5, 0x24($sp)
/* CAEE80 80240140 0200A82D */  daddu     $s5, $s0, $zero
/* CAEE84 80240144 AFB10014 */  sw        $s1, 0x14($sp)
/* CAEE88 80240148 3C118011 */  lui       $s1, 0x8011
/* CAEE8C 8024014C 2631F298 */  addiu     $s1, $s1, -0xd68
/* CAEE90 80240150 AFBF0028 */  sw        $ra, 0x28($sp)
/* CAEE94 80240154 AFB20018 */  sw        $s2, 0x18($sp)
/* CAEE98 80240158 8E6200B4 */  lw        $v0, 0xb4($s3)
/* CAEE9C 8024015C 0280182D */  daddu     $v1, $s4, $zero
/* CAEEA0 80240160 AE630084 */  sw        $v1, 0x84($s3)
/* CAEEA4 80240164 00021027 */  nor       $v0, $zero, $v0
/* CAEEA8 80240168 000217C2 */  srl       $v0, $v0, 0x1f
/* CAEEAC 8024016C 00029400 */  sll       $s2, $v0, 0x10
.L80240170:
/* CAEEB0 80240170 92220014 */  lbu       $v0, 0x14($s1)
/* CAEEB4 80240174 50400008 */  beql      $v0, $zero, .L80240198
/* CAEEB8 80240178 26100001 */   addiu    $s0, $s0, 1
/* CAEEBC 8024017C 0200202D */  daddu     $a0, $s0, $zero
/* CAEEC0 80240180 0C090035 */  jal       func_802400D4
/* CAEEC4 80240184 00122C03 */   sra      $a1, $s2, 0x10
/* CAEEC8 80240188 10540003 */  beq       $v0, $s4, .L80240198
/* CAEECC 8024018C 26100001 */   addiu    $s0, $s0, 1
/* CAEED0 80240190 08090069 */  j         .L802401A4
/* CAEED4 80240194 AE750084 */   sw       $s5, 0x84($s3)
.L80240198:
/* CAEED8 80240198 2A02000C */  slti      $v0, $s0, 0xc
/* CAEEDC 8024019C 1440FFF4 */  bnez      $v0, .L80240170
/* CAEEE0 802401A0 26310008 */   addiu    $s1, $s1, 8
.L802401A4:
/* CAEEE4 802401A4 8FBF0028 */  lw        $ra, 0x28($sp)
/* CAEEE8 802401A8 8FB50024 */  lw        $s5, 0x24($sp)
/* CAEEEC 802401AC 8FB40020 */  lw        $s4, 0x20($sp)
/* CAEEF0 802401B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* CAEEF4 802401B4 8FB20018 */  lw        $s2, 0x18($sp)
/* CAEEF8 802401B8 8FB10014 */  lw        $s1, 0x14($sp)
/* CAEEFC 802401BC 8FB00010 */  lw        $s0, 0x10($sp)
/* CAEF00 802401C0 24020002 */  addiu     $v0, $zero, 2
/* CAEF04 802401C4 03E00008 */  jr        $ra
/* CAEF08 802401C8 27BD0030 */   addiu    $sp, $sp, 0x30
