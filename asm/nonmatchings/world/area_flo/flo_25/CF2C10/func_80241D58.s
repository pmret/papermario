.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D58
/* CF4928 80241D58 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF492C 80241D5C AFBF0010 */  sw        $ra, 0x10($sp)
/* CF4930 80241D60 10A00003 */  beqz      $a1, .L80241D70
/* CF4934 80241D64 8C86000C */   lw       $a2, 0xc($a0)
/* CF4938 80241D68 3C018024 */  lui       $at, 0x8024
/* CF493C 80241D6C AC202ACC */  sw        $zero, 0x2acc($at)
.L80241D70:
/* CF4940 80241D70 3C038024 */  lui       $v1, 0x8024
/* CF4944 80241D74 24632ACC */  addiu     $v1, $v1, 0x2acc
/* CF4948 80241D78 8C620000 */  lw        $v0, ($v1)
/* CF494C 80241D7C 54400003 */  bnel      $v0, $zero, .L80241D8C
/* CF4950 80241D80 AC600000 */   sw       $zero, ($v1)
/* CF4954 80241D84 08090768 */  j         .L80241DA0
/* CF4958 80241D88 0000102D */   daddu    $v0, $zero, $zero
.L80241D8C:
/* CF495C 80241D8C 8CC50000 */  lw        $a1, ($a2)
/* CF4960 80241D90 3C068024 */  lui       $a2, 0x8024
/* CF4964 80241D94 0C0B2026 */  jal       set_variable
/* CF4968 80241D98 8CC62AD0 */   lw       $a2, 0x2ad0($a2)
/* CF496C 80241D9C 24020002 */  addiu     $v0, $zero, 2
.L80241DA0:
/* CF4970 80241DA0 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF4974 80241DA4 03E00008 */  jr        $ra
/* CF4978 80241DA8 27BD0018 */   addiu    $sp, $sp, 0x18
