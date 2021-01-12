.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240200_EED300
/* EED300 80240200 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EED304 80240204 AFB3001C */  sw        $s3, 0x1c($sp)
/* EED308 80240208 0080982D */  daddu     $s3, $a0, $zero
/* EED30C 8024020C AFB00010 */  sw        $s0, 0x10($sp)
/* EED310 80240210 24100001 */  addiu     $s0, $zero, 1
/* EED314 80240214 AFB40020 */  sw        $s4, 0x20($sp)
/* EED318 80240218 2414FFFF */  addiu     $s4, $zero, -1
/* EED31C 8024021C AFB50024 */  sw        $s5, 0x24($sp)
/* EED320 80240220 0200A82D */  daddu     $s5, $s0, $zero
/* EED324 80240224 AFB10014 */  sw        $s1, 0x14($sp)
/* EED328 80240228 3C118011 */  lui       $s1, %hi(D_80117848)
/* EED32C 8024022C 26317848 */  addiu     $s1, $s1, %lo(D_80117848)
/* EED330 80240230 AFBF0028 */  sw        $ra, 0x28($sp)
/* EED334 80240234 AFB20018 */  sw        $s2, 0x18($sp)
/* EED338 80240238 8E6200B4 */  lw        $v0, 0xb4($s3)
/* EED33C 8024023C 0280182D */  daddu     $v1, $s4, $zero
/* EED340 80240240 AE630084 */  sw        $v1, 0x84($s3)
/* EED344 80240244 00021027 */  nor       $v0, $zero, $v0
/* EED348 80240248 000217C2 */  srl       $v0, $v0, 0x1f
/* EED34C 8024024C 00029400 */  sll       $s2, $v0, 0x10
.L80240250:
/* EED350 80240250 92220014 */  lbu       $v0, 0x14($s1)
/* EED354 80240254 50400008 */  beql      $v0, $zero, .L80240278
/* EED358 80240258 26100001 */   addiu    $s0, $s0, 1
/* EED35C 8024025C 0200202D */  daddu     $a0, $s0, $zero
/* EED360 80240260 0C09006D */  jal       func_802401B4_EED2B4
/* EED364 80240264 00122C03 */   sra      $a1, $s2, 0x10
/* EED368 80240268 10540003 */  beq       $v0, $s4, .L80240278
/* EED36C 8024026C 26100001 */   addiu    $s0, $s0, 1
/* EED370 80240270 080900A1 */  j         .L80240284
/* EED374 80240274 AE750084 */   sw       $s5, 0x84($s3)
.L80240278:
/* EED378 80240278 2A02000C */  slti      $v0, $s0, 0xc
/* EED37C 8024027C 1440FFF4 */  bnez      $v0, .L80240250
/* EED380 80240280 26310008 */   addiu    $s1, $s1, 8
.L80240284:
/* EED384 80240284 8FBF0028 */  lw        $ra, 0x28($sp)
/* EED388 80240288 8FB50024 */  lw        $s5, 0x24($sp)
/* EED38C 8024028C 8FB40020 */  lw        $s4, 0x20($sp)
/* EED390 80240290 8FB3001C */  lw        $s3, 0x1c($sp)
/* EED394 80240294 8FB20018 */  lw        $s2, 0x18($sp)
/* EED398 80240298 8FB10014 */  lw        $s1, 0x14($sp)
/* EED39C 8024029C 8FB00010 */  lw        $s0, 0x10($sp)
/* EED3A0 802402A0 24020002 */  addiu     $v0, $zero, 2
/* EED3A4 802402A4 03E00008 */  jr        $ra
/* EED3A8 802402A8 27BD0030 */   addiu    $sp, $sp, 0x30
