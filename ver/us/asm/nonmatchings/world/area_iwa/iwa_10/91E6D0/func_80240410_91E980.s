.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240410_91E980
/* 91E980 80240410 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 91E984 80240414 AFB3001C */  sw        $s3, 0x1c($sp)
/* 91E988 80240418 0080982D */  daddu     $s3, $a0, $zero
/* 91E98C 8024041C AFB00010 */  sw        $s0, 0x10($sp)
/* 91E990 80240420 24100001 */  addiu     $s0, $zero, 1
/* 91E994 80240424 AFB40020 */  sw        $s4, 0x20($sp)
/* 91E998 80240428 2414FFFF */  addiu     $s4, $zero, -1
/* 91E99C 8024042C AFB50024 */  sw        $s5, 0x24($sp)
/* 91E9A0 80240430 0200A82D */  daddu     $s5, $s0, $zero
/* 91E9A4 80240434 AFB10014 */  sw        $s1, 0x14($sp)
/* 91E9A8 80240438 3C118011 */  lui       $s1, %hi(gPlayerData+0x8)
/* 91E9AC 8024043C 2631F298 */  addiu     $s1, $s1, %lo(gPlayerData+0x8)
/* 91E9B0 80240440 AFBF0028 */  sw        $ra, 0x28($sp)
/* 91E9B4 80240444 AFB20018 */  sw        $s2, 0x18($sp)
/* 91E9B8 80240448 8E6200B4 */  lw        $v0, 0xb4($s3)
/* 91E9BC 8024044C 0280182D */  daddu     $v1, $s4, $zero
/* 91E9C0 80240450 AE630084 */  sw        $v1, 0x84($s3)
/* 91E9C4 80240454 00021027 */  nor       $v0, $zero, $v0
/* 91E9C8 80240458 000217C2 */  srl       $v0, $v0, 0x1f
/* 91E9CC 8024045C 00029400 */  sll       $s2, $v0, 0x10
.L80240460:
/* 91E9D0 80240460 92220014 */  lbu       $v0, 0x14($s1)
/* 91E9D4 80240464 50400008 */  beql      $v0, $zero, .L80240488
/* 91E9D8 80240468 26100001 */   addiu    $s0, $s0, 1
/* 91E9DC 8024046C 0200202D */  daddu     $a0, $s0, $zero
/* 91E9E0 80240470 0C0900F1 */  jal       func_802403C4_91E934
/* 91E9E4 80240474 00122C03 */   sra      $a1, $s2, 0x10
/* 91E9E8 80240478 10540003 */  beq       $v0, $s4, .L80240488
/* 91E9EC 8024047C 26100001 */   addiu    $s0, $s0, 1
/* 91E9F0 80240480 08090125 */  j         .L80240494
/* 91E9F4 80240484 AE750084 */   sw       $s5, 0x84($s3)
.L80240488:
/* 91E9F8 80240488 2A02000C */  slti      $v0, $s0, 0xc
/* 91E9FC 8024048C 1440FFF4 */  bnez      $v0, .L80240460
/* 91EA00 80240490 26310008 */   addiu    $s1, $s1, 8
.L80240494:
/* 91EA04 80240494 8FBF0028 */  lw        $ra, 0x28($sp)
/* 91EA08 80240498 8FB50024 */  lw        $s5, 0x24($sp)
/* 91EA0C 8024049C 8FB40020 */  lw        $s4, 0x20($sp)
/* 91EA10 802404A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 91EA14 802404A4 8FB20018 */  lw        $s2, 0x18($sp)
/* 91EA18 802404A8 8FB10014 */  lw        $s1, 0x14($sp)
/* 91EA1C 802404AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 91EA20 802404B0 24020002 */  addiu     $v0, $zero, 2
/* 91EA24 802404B4 03E00008 */  jr        $ra
/* 91EA28 802404B8 27BD0030 */   addiu    $sp, $sp, 0x30
