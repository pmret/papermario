.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_trigger
/* DBE6C 8014576C 3C038016 */  lui       $v1, %hi(gCurrentTriggerListPtr)
/* DBE70 80145770 8C639390 */  lw        $v1, %lo(gCurrentTriggerListPtr)($v1)
/* DBE74 80145774 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DBE78 80145778 AFB10014 */  sw        $s1, 0x14($sp)
/* DBE7C 8014577C 0080882D */  daddu     $s1, $a0, $zero
/* DBE80 80145780 AFB00010 */  sw        $s0, 0x10($sp)
/* DBE84 80145784 0000802D */  daddu     $s0, $zero, $zero
/* DBE88 80145788 AFBF0018 */  sw        $ra, 0x18($sp)
.L8014578C:
/* DBE8C 8014578C 8C620000 */  lw        $v0, ($v1)
/* DBE90 80145790 10400006 */  beqz      $v0, .L801457AC
/* DBE94 80145794 2A020040 */   slti     $v0, $s0, 0x40
/* DBE98 80145798 26100001 */  addiu     $s0, $s0, 1
/* DBE9C 8014579C 2A020040 */  slti      $v0, $s0, 0x40
/* DBEA0 801457A0 1440FFFA */  bnez      $v0, .L8014578C
/* DBEA4 801457A4 24630004 */   addiu    $v1, $v1, 4
/* DBEA8 801457A8 2A020040 */  slti      $v0, $s0, 0x40
.L801457AC:
/* DBEAC 801457AC 14400003 */  bnez      $v0, .L801457BC
/* DBEB0 801457B0 00000000 */   nop
.L801457B4:
/* DBEB4 801457B4 080515ED */  j         .L801457B4
/* DBEB8 801457B8 00000000 */   nop
.L801457BC:
/* DBEBC 801457BC 0C00AB39 */  jal       heap_malloc
/* DBEC0 801457C0 24040038 */   addiu    $a0, $zero, 0x38
/* DBEC4 801457C4 00102080 */  sll       $a0, $s0, 2
/* DBEC8 801457C8 3C038016 */  lui       $v1, %hi(gCurrentTriggerListPtr)
/* DBECC 801457CC 8C639390 */  lw        $v1, %lo(gCurrentTriggerListPtr)($v1)
/* DBED0 801457D0 3C058015 */  lui       $a1, %hi(gTriggerCount)
/* DBED4 801457D4 24A51334 */  addiu     $a1, $a1, %lo(gTriggerCount)
/* DBED8 801457D8 00832021 */  addu      $a0, $a0, $v1
/* DBEDC 801457DC 94A30000 */  lhu       $v1, ($a1)
/* DBEE0 801457E0 0040302D */  daddu     $a2, $v0, $zero
/* DBEE4 801457E4 AC860000 */  sw        $a2, ($a0)
/* DBEE8 801457E8 24630001 */  addiu     $v1, $v1, 1
/* DBEEC 801457EC 14C00003 */  bnez      $a2, .L801457FC
/* DBEF0 801457F0 A4A30000 */   sh       $v1, ($a1)
.L801457F4:
/* DBEF4 801457F4 080515FD */  j         .L801457F4
/* DBEF8 801457F8 00000000 */   nop
.L801457FC:
/* DBEFC 801457FC 8E220000 */  lw        $v0, ($s1)
/* DBF00 80145800 34420001 */  ori       $v0, $v0, 1
/* DBF04 80145804 ACC20000 */  sw        $v0, ($a2)
/* DBF08 80145808 86220004 */  lh        $v0, 4($s1)
/* DBF0C 8014580C ACC20004 */  sw        $v0, 4($a2)
/* DBF10 80145810 8E220008 */  lw        $v0, 8($s1)
/* DBF14 80145814 ACC20008 */  sw        $v0, 8($a2)
/* DBF18 80145818 8E22001C */  lw        $v0, 0x1c($s1)
/* DBF1C 8014581C ACC20028 */  sw        $v0, 0x28($a2)
/* DBF20 80145820 8E220014 */  lw        $v0, 0x14($s1)
/* DBF24 80145824 ACC2002C */  sw        $v0, 0x2c($a2)
/* DBF28 80145828 9222001B */  lbu       $v0, 0x1b($s1)
/* DBF2C 8014582C A0C20030 */  sb        $v0, 0x30($a2)
/* DBF30 80145830 8E22000C */  lw        $v0, 0xc($s1)
/* DBF34 80145834 14400004 */  bnez      $v0, .L80145848
/* DBF38 80145838 ACC2000C */   sw       $v0, 0xc($a2)
/* DBF3C 8014583C 3C028014 */  lui       $v0, %hi(default_trigger_function_handler)
/* DBF40 80145840 24425670 */  addiu     $v0, $v0, %lo(default_trigger_function_handler)
/* DBF44 80145844 ACC2000C */  sw        $v0, 0xc($a2)
.L80145848:
/* DBF48 80145848 8FBF0018 */  lw        $ra, 0x18($sp)
/* DBF4C 8014584C 8FB10014 */  lw        $s1, 0x14($sp)
/* DBF50 80145850 8FB00010 */  lw        $s0, 0x10($sp)
/* DBF54 80145854 00C0102D */  daddu     $v0, $a2, $zero
/* DBF58 80145858 03E00008 */  jr        $ra
/* DBF5C 8014585C 27BD0020 */   addiu    $sp, $sp, 0x20
