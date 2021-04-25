.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel omo_11_UnkFunc38
/* DDD0E0 802408B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DDD0E4 802408B4 AFB3001C */  sw        $s3, 0x1c($sp)
/* DDD0E8 802408B8 0080982D */  daddu     $s3, $a0, $zero
/* DDD0EC 802408BC AFB00010 */  sw        $s0, 0x10($sp)
/* DDD0F0 802408C0 24100001 */  addiu     $s0, $zero, 1
/* DDD0F4 802408C4 AFB40020 */  sw        $s4, 0x20($sp)
/* DDD0F8 802408C8 2414FFFF */  addiu     $s4, $zero, -1
/* DDD0FC 802408CC AFB50024 */  sw        $s5, 0x24($sp)
/* DDD100 802408D0 0200A82D */  daddu     $s5, $s0, $zero
/* DDD104 802408D4 AFB10014 */  sw        $s1, 0x14($sp)
/* DDD108 802408D8 3C118011 */  lui       $s1, %hi(gPlayerData+0x8)
/* DDD10C 802408DC 2631F298 */  addiu     $s1, $s1, %lo(gPlayerData+0x8)
/* DDD110 802408E0 AFBF0028 */  sw        $ra, 0x28($sp)
/* DDD114 802408E4 AFB20018 */  sw        $s2, 0x18($sp)
/* DDD118 802408E8 8E6200B4 */  lw        $v0, 0xb4($s3)
/* DDD11C 802408EC 0280182D */  daddu     $v1, $s4, $zero
/* DDD120 802408F0 AE630084 */  sw        $v1, 0x84($s3)
/* DDD124 802408F4 00021027 */  nor       $v0, $zero, $v0
/* DDD128 802408F8 000217C2 */  srl       $v0, $v0, 0x1f
/* DDD12C 802408FC 00029400 */  sll       $s2, $v0, 0x10
.L80240900:
/* DDD130 80240900 92220014 */  lbu       $v0, 0x14($s1)
/* DDD134 80240904 50400008 */  beql      $v0, $zero, .L80240928
/* DDD138 80240908 26100001 */   addiu    $s0, $s0, 1
/* DDD13C 8024090C 0200202D */  daddu     $a0, $s0, $zero
/* DDD140 80240910 0C090219 */  jal       omo_11_UnkFunc37
/* DDD144 80240914 00122C03 */   sra      $a1, $s2, 0x10
/* DDD148 80240918 10540003 */  beq       $v0, $s4, .L80240928
/* DDD14C 8024091C 26100001 */   addiu    $s0, $s0, 1
/* DDD150 80240920 0809024D */  j         .L80240934
/* DDD154 80240924 AE750084 */   sw       $s5, 0x84($s3)
.L80240928:
/* DDD158 80240928 2A02000C */  slti      $v0, $s0, 0xc
/* DDD15C 8024092C 1440FFF4 */  bnez      $v0, .L80240900
/* DDD160 80240930 26310008 */   addiu    $s1, $s1, 8
.L80240934:
/* DDD164 80240934 8FBF0028 */  lw        $ra, 0x28($sp)
/* DDD168 80240938 8FB50024 */  lw        $s5, 0x24($sp)
/* DDD16C 8024093C 8FB40020 */  lw        $s4, 0x20($sp)
/* DDD170 80240940 8FB3001C */  lw        $s3, 0x1c($sp)
/* DDD174 80240944 8FB20018 */  lw        $s2, 0x18($sp)
/* DDD178 80240948 8FB10014 */  lw        $s1, 0x14($sp)
/* DDD17C 8024094C 8FB00010 */  lw        $s0, 0x10($sp)
/* DDD180 80240950 24020002 */  addiu     $v0, $zero, 2
/* DDD184 80240954 03E00008 */  jr        $ra
/* DDD188 80240958 27BD0030 */   addiu    $sp, $sp, 0x30
