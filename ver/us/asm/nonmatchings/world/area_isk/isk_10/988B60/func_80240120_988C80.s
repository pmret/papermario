.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel isk_10_UnkFunc38
/* 988C80 80240120 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 988C84 80240124 AFB3001C */  sw        $s3, 0x1c($sp)
/* 988C88 80240128 0080982D */  daddu     $s3, $a0, $zero
/* 988C8C 8024012C AFB00010 */  sw        $s0, 0x10($sp)
/* 988C90 80240130 24100001 */  addiu     $s0, $zero, 1
/* 988C94 80240134 AFB40020 */  sw        $s4, 0x20($sp)
/* 988C98 80240138 2414FFFF */  addiu     $s4, $zero, -1
/* 988C9C 8024013C AFB50024 */  sw        $s5, 0x24($sp)
/* 988CA0 80240140 0200A82D */  daddu     $s5, $s0, $zero
/* 988CA4 80240144 AFB10014 */  sw        $s1, 0x14($sp)
/* 988CA8 80240148 3C118011 */  lui       $s1, %hi(gPlayerData+0x8)
/* 988CAC 8024014C 2631F298 */  addiu     $s1, $s1, %lo(gPlayerData+0x8)
/* 988CB0 80240150 AFBF0028 */  sw        $ra, 0x28($sp)
/* 988CB4 80240154 AFB20018 */  sw        $s2, 0x18($sp)
/* 988CB8 80240158 8E6200B4 */  lw        $v0, 0xb4($s3)
/* 988CBC 8024015C 0280182D */  daddu     $v1, $s4, $zero
/* 988CC0 80240160 AE630084 */  sw        $v1, 0x84($s3)
/* 988CC4 80240164 00021027 */  nor       $v0, $zero, $v0
/* 988CC8 80240168 000217C2 */  srl       $v0, $v0, 0x1f
/* 988CCC 8024016C 00029400 */  sll       $s2, $v0, 0x10
.L80240170:
/* 988CD0 80240170 92220014 */  lbu       $v0, 0x14($s1)
/* 988CD4 80240174 50400008 */  beql      $v0, $zero, .L80240198
/* 988CD8 80240178 26100001 */   addiu    $s0, $s0, 1
/* 988CDC 8024017C 0200202D */  daddu     $a0, $s0, $zero
/* 988CE0 80240180 0C090035 */  jal       isk_10_UnkFunc37
/* 988CE4 80240184 00122C03 */   sra      $a1, $s2, 0x10
/* 988CE8 80240188 10540003 */  beq       $v0, $s4, .L80240198
/* 988CEC 8024018C 26100001 */   addiu    $s0, $s0, 1
/* 988CF0 80240190 08090069 */  j         .L802401A4
/* 988CF4 80240194 AE750084 */   sw       $s5, 0x84($s3)
.L80240198:
/* 988CF8 80240198 2A02000C */  slti      $v0, $s0, 0xc
/* 988CFC 8024019C 1440FFF4 */  bnez      $v0, .L80240170
/* 988D00 802401A0 26310008 */   addiu    $s1, $s1, 8
.L802401A4:
/* 988D04 802401A4 8FBF0028 */  lw        $ra, 0x28($sp)
/* 988D08 802401A8 8FB50024 */  lw        $s5, 0x24($sp)
/* 988D0C 802401AC 8FB40020 */  lw        $s4, 0x20($sp)
/* 988D10 802401B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 988D14 802401B4 8FB20018 */  lw        $s2, 0x18($sp)
/* 988D18 802401B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 988D1C 802401BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 988D20 802401C0 24020002 */  addiu     $v0, $zero, 2
/* 988D24 802401C4 03E00008 */  jr        $ra
/* 988D28 802401C8 27BD0030 */   addiu    $sp, $sp, 0x30
