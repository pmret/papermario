.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240308_A7A808
/* A7A808 80240308 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A7A80C 8024030C AFBF0010 */  sw        $ra, 0x10($sp)
/* A7A810 80240310 8C82000C */  lw        $v0, 0xc($a0)
/* A7A814 80240314 0C0B1EAF */  jal       evt_get_variable
/* A7A818 80240318 8C450000 */   lw       $a1, ($v0)
/* A7A81C 8024031C 0040182D */  daddu     $v1, $v0, $zero
/* A7A820 80240320 10600012 */  beqz      $v1, .L8024036C
/* A7A824 80240324 0000202D */   daddu    $a0, $zero, $zero
/* A7A828 80240328 8C620000 */  lw        $v0, ($v1)
/* A7A82C 8024032C 5040000A */  beql      $v0, $zero, .L80240358
/* A7A830 80240330 00041080 */   sll      $v0, $a0, 2
/* A7A834 80240334 3C058025 */  lui       $a1, %hi(D_80248F90)
/* A7A838 80240338 24A58F90 */  addiu     $a1, $a1, %lo(D_80248F90)
.L8024033C:
/* A7A83C 8024033C 24630004 */  addiu     $v1, $v1, 4
/* A7A840 80240340 24840001 */  addiu     $a0, $a0, 1
/* A7A844 80240344 ACA20000 */  sw        $v0, ($a1)
/* A7A848 80240348 8C620000 */  lw        $v0, ($v1)
/* A7A84C 8024034C 1440FFFB */  bnez      $v0, .L8024033C
/* A7A850 80240350 24A50004 */   addiu    $a1, $a1, 4
/* A7A854 80240354 00041080 */  sll       $v0, $a0, 2
.L80240358:
/* A7A858 80240358 3C018025 */  lui       $at, %hi(D_80248F90)
/* A7A85C 8024035C 00220821 */  addu      $at, $at, $v0
/* A7A860 80240360 AC208F90 */  sw        $zero, %lo(D_80248F90)($at)
/* A7A864 80240364 080900E5 */  j         .L80240394
/* A7A868 80240368 00000000 */   nop
.L8024036C:
/* A7A86C 8024036C 3C038025 */  lui       $v1, %hi(D_80248F90)
/* A7A870 80240370 24638F90 */  addiu     $v1, $v1, %lo(D_80248F90)
/* A7A874 80240374 0060282D */  daddu     $a1, $v1, $zero
.L80240378:
/* A7A878 80240378 24820010 */  addiu     $v0, $a0, 0x10
/* A7A87C 8024037C AC620000 */  sw        $v0, ($v1)
/* A7A880 80240380 24630004 */  addiu     $v1, $v1, 4
/* A7A884 80240384 24840001 */  addiu     $a0, $a0, 1
/* A7A888 80240388 28820070 */  slti      $v0, $a0, 0x70
/* A7A88C 8024038C 1440FFFA */  bnez      $v0, .L80240378
/* A7A890 80240390 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80240394:
/* A7A894 80240394 8FBF0010 */  lw        $ra, 0x10($sp)
/* A7A898 80240398 24020002 */  addiu     $v0, $zero, 2
/* A7A89C 8024039C 03E00008 */  jr        $ra
/* A7A8A0 802403A0 27BD0018 */   addiu    $sp, $sp, 0x18
