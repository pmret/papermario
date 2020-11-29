.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E6428
/* 7F8D8 800E6428 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7F8DC 800E642C 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* 7F8E0 800E6430 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* 7F8E4 800E6434 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7F8E8 800E6438 808200B4 */  lb        $v0, 0xb4($a0)
/* 7F8EC 800E643C 2C420003 */  sltiu     $v0, $v0, 3
/* 7F8F0 800E6440 1040002C */  beqz      $v0, .L800E64F4
/* 7F8F4 800E6444 0080282D */   daddu    $a1, $a0, $zero
/* 7F8F8 800E6448 3C038011 */  lui       $v1, %hi(D_8010C92C)
/* 7F8FC 800E644C 2463C92C */  addiu     $v1, $v1, %lo(D_8010C92C)
/* 7F900 800E6450 8C620000 */  lw        $v0, ($v1)
/* 7F904 800E6454 1040001B */  beqz      $v0, .L800E64C4
/* 7F908 800E6458 2442FFFF */   addiu    $v0, $v0, -1
/* 7F90C 800E645C 14400025 */  bnez      $v0, .L800E64F4
/* 7F910 800E6460 AC620000 */   sw       $v0, ($v1)
/* 7F914 800E6464 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* 7F918 800E6468 24A5419C */  addiu     $a1, $a1, %lo(gGameStatusPtr)
/* 7F91C 800E646C 8CA30000 */  lw        $v1, ($a1)
/* 7F920 800E6470 9062007E */  lbu       $v0, 0x7e($v1)
/* 7F924 800E6474 30420002 */  andi      $v0, $v0, 2
/* 7F928 800E6478 1040001E */  beqz      $v0, .L800E64F4
/* 7F92C 800E647C 00000000 */   nop      
/* 7F930 800E6480 8C820004 */  lw        $v0, 4($a0)
/* 7F934 800E6484 34422000 */  ori       $v0, $v0, 0x2000
/* 7F938 800E6488 AC820004 */  sw        $v0, 4($a0)
/* 7F93C 800E648C 9062007E */  lbu       $v0, 0x7e($v1)
/* 7F940 800E6490 34420002 */  ori       $v0, $v0, 2
/* 7F944 800E6494 A062007E */  sb        $v0, 0x7e($v1)
/* 7F948 800E6498 8CA20000 */  lw        $v0, ($a1)
/* 7F94C 800E649C 0C03995F */  jal       make_disguise_npc
/* 7F950 800E64A0 8044007F */   lb       $a0, 0x7f($v0)
/* 7F954 800E64A4 0040202D */  daddu     $a0, $v0, $zero
/* 7F958 800E64A8 10800012 */  beqz      $a0, .L800E64F4
/* 7F95C 800E64AC 3C03FFFB */   lui      $v1, 0xfffb
/* 7F960 800E64B0 8C820000 */  lw        $v0, ($a0)
/* 7F964 800E64B4 3463FFFF */  ori       $v1, $v1, 0xffff
/* 7F968 800E64B8 00431024 */  and       $v0, $v0, $v1
/* 7F96C 800E64BC 0803993D */  j         .L800E64F4
/* 7F970 800E64C0 AC820000 */   sw       $v0, ($a0)
.L800E64C4:
/* 7F974 800E64C4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7F978 800E64C8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7F97C 800E64CC 9042007E */  lbu       $v0, 0x7e($v0)
/* 7F980 800E64D0 30420004 */  andi      $v0, $v0, 4
/* 7F984 800E64D4 10400007 */  beqz      $v0, .L800E64F4
/* 7F988 800E64D8 00000000 */   nop      
/* 7F98C 800E64DC 8CA200E0 */  lw        $v0, 0xe0($a1)
/* 7F990 800E64E0 30424000 */  andi      $v0, $v0, 0x4000
/* 7F994 800E64E4 10400003 */  beqz      $v0, .L800E64F4
/* 7F998 800E64E8 00000000 */   nop      
/* 7F99C 800E64EC 0C039769 */  jal       set_action_state
/* 7F9A0 800E64F0 24040019 */   addiu    $a0, $zero, 0x19
.L800E64F4:
/* 7F9A4 800E64F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7F9A8 800E64F8 03E00008 */  jr        $ra
/* 7F9AC 800E64FC 27BD0018 */   addiu    $sp, $sp, 0x18
