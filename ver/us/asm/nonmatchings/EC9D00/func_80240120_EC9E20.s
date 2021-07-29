.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240120_EC9E20
/* EC9E20 80240120 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EC9E24 80240124 AFB3001C */  sw        $s3, 0x1c($sp)
/* EC9E28 80240128 0080982D */  daddu     $s3, $a0, $zero
/* EC9E2C 8024012C AFB00010 */  sw        $s0, 0x10($sp)
/* EC9E30 80240130 24100001 */  addiu     $s0, $zero, 1
/* EC9E34 80240134 AFB40020 */  sw        $s4, 0x20($sp)
/* EC9E38 80240138 2414FFFF */  addiu     $s4, $zero, -1
/* EC9E3C 8024013C AFB50024 */  sw        $s5, 0x24($sp)
/* EC9E40 80240140 0200A82D */  daddu     $s5, $s0, $zero
/* EC9E44 80240144 AFB10014 */  sw        $s1, 0x14($sp)
/* EC9E48 80240148 3C118011 */  lui       $s1, %hi(D_80117848)
/* EC9E4C 8024014C 26317848 */  addiu     $s1, $s1, %lo(D_80117848)
/* EC9E50 80240150 AFBF0028 */  sw        $ra, 0x28($sp)
/* EC9E54 80240154 AFB20018 */  sw        $s2, 0x18($sp)
/* EC9E58 80240158 8E6200B4 */  lw        $v0, 0xb4($s3)
/* EC9E5C 8024015C 0280182D */  daddu     $v1, $s4, $zero
/* EC9E60 80240160 AE630084 */  sw        $v1, 0x84($s3)
/* EC9E64 80240164 00021027 */  nor       $v0, $zero, $v0
/* EC9E68 80240168 000217C2 */  srl       $v0, $v0, 0x1f
/* EC9E6C 8024016C 00029400 */  sll       $s2, $v0, 0x10
.L80240170:
/* EC9E70 80240170 92220014 */  lbu       $v0, 0x14($s1)
/* EC9E74 80240174 50400008 */  beql      $v0, $zero, .L80240198
/* EC9E78 80240178 26100001 */   addiu    $s0, $s0, 1
/* EC9E7C 8024017C 0200202D */  daddu     $a0, $s0, $zero
/* EC9E80 80240180 0C090035 */  jal       func_802400D4_EC9DD4
/* EC9E84 80240184 00122C03 */   sra      $a1, $s2, 0x10
/* EC9E88 80240188 10540003 */  beq       $v0, $s4, .L80240198
/* EC9E8C 8024018C 26100001 */   addiu    $s0, $s0, 1
/* EC9E90 80240190 08090069 */  j         .L802401A4
/* EC9E94 80240194 AE750084 */   sw       $s5, 0x84($s3)
.L80240198:
/* EC9E98 80240198 2A02000C */  slti      $v0, $s0, 0xc
/* EC9E9C 8024019C 1440FFF4 */  bnez      $v0, .L80240170
/* EC9EA0 802401A0 26310008 */   addiu    $s1, $s1, 8
.L802401A4:
/* EC9EA4 802401A4 8FBF0028 */  lw        $ra, 0x28($sp)
/* EC9EA8 802401A8 8FB50024 */  lw        $s5, 0x24($sp)
/* EC9EAC 802401AC 8FB40020 */  lw        $s4, 0x20($sp)
/* EC9EB0 802401B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* EC9EB4 802401B4 8FB20018 */  lw        $s2, 0x18($sp)
/* EC9EB8 802401B8 8FB10014 */  lw        $s1, 0x14($sp)
/* EC9EBC 802401BC 8FB00010 */  lw        $s0, 0x10($sp)
/* EC9EC0 802401C0 24020002 */  addiu     $v0, $zero, 2
/* EC9EC4 802401C4 03E00008 */  jr        $ra
/* EC9EC8 802401C8 27BD0030 */   addiu    $sp, $sp, 0x30
