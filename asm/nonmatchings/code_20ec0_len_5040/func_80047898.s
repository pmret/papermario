.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047898
/* 22C98 80047898 00041040 */  sll       $v0, $a0, 1
/* 22C9C 8004789C 00441021 */  addu      $v0, $v0, $a0
/* 22CA0 800478A0 00021080 */  sll       $v0, $v0, 2
/* 22CA4 800478A4 00441023 */  subu      $v0, $v0, $a0
/* 22CA8 800478A8 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 22CAC 800478AC 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 22CB0 800478B0 00021100 */  sll       $v0, $v0, 4
/* 22CB4 800478B4 00622021 */  addu      $a0, $v1, $v0
/* 22CB8 800478B8 80820038 */  lb        $v0, 0x38($a0)
/* 22CBC 800478BC 1040000C */  beqz      $v0, .L800478F0
/* 22CC0 800478C0 90830038 */   lbu      $v1, 0x38($a0)
/* 22CC4 800478C4 80820039 */  lb        $v0, 0x39($a0)
/* 22CC8 800478C8 14400009 */  bnez      $v0, .L800478F0
/* 22CCC 800478CC 24020001 */   addiu    $v0, $zero, 1
/* 22CD0 800478D0 A0830039 */  sb        $v1, 0x39($a0)
/* 22CD4 800478D4 8C830040 */  lw        $v1, 0x40($a0)
/* 22CD8 800478D8 A082003B */  sb        $v0, 0x3b($a0)
/* 22CDC 800478DC 2402000A */  addiu     $v0, $zero, 0xa
/* 22CE0 800478E0 A0800038 */  sb        $zero, 0x38($a0)
/* 22CE4 800478E4 A080003A */  sb        $zero, 0x3a($a0)
/* 22CE8 800478E8 A082003D */  sb        $v0, 0x3d($a0)
/* 22CEC 800478EC AC830044 */  sw        $v1, 0x44($a0)
.L800478F0:
/* 22CF0 800478F0 03E00008 */  jr        $ra
/* 22CF4 800478F4 00000000 */   nop      
