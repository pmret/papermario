.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel RemoveActor
/* 1AB090 8027C7B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1AB094 8027C7B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AB098 8027C7B8 0080802D */  daddu     $s0, $a0, $zero
/* 1AB09C 8027C7BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 1AB0A0 8027C7C0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1AB0A4 8027C7C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AB0A8 8027C7C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AB0AC 8027C7CC 8E02000C */  lw        $v0, 0xc($s0)
/* 1AB0B0 8027C7D0 0C0B1EAF */  jal       get_variable
/* 1AB0B4 8027C7D4 8C450000 */   lw       $a1, ($v0)
/* 1AB0B8 8027C7D8 0040882D */  daddu     $s1, $v0, $zero
/* 1AB0BC 8027C7DC 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 1AB0C0 8027C7E0 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 1AB0C4 8027C7E4 3C13800B */  lui       $s3, %hi(gCurrentEncounter)
/* 1AB0C8 8027C7E8 26730F10 */  addiu     $s3, $s3, %lo(gCurrentEncounter)
/* 1AB0CC 8027C7EC 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AB0D0 8027C7F0 16220002 */  bne       $s1, $v0, .L8027C7FC
/* 1AB0D4 8027C7F4 00000000 */   nop
/* 1AB0D8 8027C7F8 8E110148 */  lw        $s1, 0x148($s0)
.L8027C7FC:
/* 1AB0DC 8027C7FC 0C09A75B */  jal       get_actor
/* 1AB0E0 8027C800 0220202D */   daddu    $a0, $s1, $zero
/* 1AB0E4 8027C804 0000282D */  daddu     $a1, $zero, $zero
/* 1AB0E8 8027C808 0040202D */  daddu     $a0, $v0, $zero
/* 1AB0EC 8027C80C 82460171 */  lb        $a2, 0x171($s2)
/* 1AB0F0 8027C810 18C0000D */  blez      $a2, .L8027C848
/* 1AB0F4 8027C814 26420140 */   addiu    $v0, $s2, 0x140
/* 1AB0F8 8027C818 2407FFFF */  addiu     $a3, $zero, -1
/* 1AB0FC 8027C81C 0040182D */  daddu     $v1, $v0, $zero
.L8027C820:
/* 1AB100 8027C820 90620001 */  lbu       $v0, 1($v1)
/* 1AB104 8027C824 00021080 */  sll       $v0, $v0, 2
/* 1AB108 8027C828 02421021 */  addu      $v0, $s2, $v0
/* 1AB10C 8027C82C 8C4200E0 */  lw        $v0, 0xe0($v0)
/* 1AB110 8027C830 50820001 */  beql      $a0, $v0, .L8027C838
/* 1AB114 8027C834 A4670000 */   sh       $a3, ($v1)
.L8027C838:
/* 1AB118 8027C838 24A50001 */  addiu     $a1, $a1, 1
/* 1AB11C 8027C83C 00A6102A */  slt       $v0, $a1, $a2
/* 1AB120 8027C840 1440FFF7 */  bnez      $v0, .L8027C820
/* 1AB124 8027C844 24630002 */   addiu    $v1, $v1, 2
.L8027C848:
/* 1AB128 8027C848 90820207 */  lbu       $v0, 0x207($a0)
/* 1AB12C 8027C84C 9663000E */  lhu       $v1, 0xe($s3)
/* 1AB130 8027C850 00021600 */  sll       $v0, $v0, 0x18
/* 1AB134 8027C854 00021603 */  sra       $v0, $v0, 0x18
/* 1AB138 8027C858 00621821 */  addu      $v1, $v1, $v0
/* 1AB13C 8027C85C A663000E */  sh        $v1, 0xe($s3)
/* 1AB140 8027C860 8C820008 */  lw        $v0, 8($a0)
/* 1AB144 8027C864 9042001F */  lbu       $v0, 0x1f($v0)
/* 1AB148 8027C868 00621821 */  addu      $v1, $v1, $v0
/* 1AB14C 8027C86C 0C0902EF */  jal       delete_actor
/* 1AB150 8027C870 A663000E */   sh       $v1, 0xe($s3)
/* 1AB154 8027C874 24020002 */  addiu     $v0, $zero, 2
/* 1AB158 8027C878 322300FF */  andi      $v1, $s1, 0xff
/* 1AB15C 8027C87C 00431804 */  sllv      $v1, $v1, $v0
/* 1AB160 8027C880 02431821 */  addu      $v1, $s2, $v1
/* 1AB164 8027C884 AC6000E0 */  sw        $zero, 0xe0($v1)
/* 1AB168 8027C888 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1AB16C 8027C88C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1AB170 8027C890 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AB174 8027C894 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AB178 8027C898 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AB17C 8027C89C 03E00008 */  jr        $ra
/* 1AB180 8027C8A0 27BD0028 */   addiu    $sp, $sp, 0x28
