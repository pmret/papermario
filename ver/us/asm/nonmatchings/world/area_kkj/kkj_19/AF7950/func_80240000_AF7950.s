.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AF7950
/* AF7950 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF7954 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF7958 80240008 8C82000C */  lw        $v0, 0xc($a0)
/* AF795C 8024000C 0C0B1EAF */  jal       get_variable
/* AF7960 80240010 8C450000 */   lw       $a1, ($v0)
/* AF7964 80240014 0000202D */  daddu     $a0, $zero, $zero
/* AF7968 80240018 3C05F971 */  lui       $a1, 0xf971
/* AF796C 8024001C 3C018024 */  lui       $at, %hi(D_80240E90_AF87E0)
/* AF7970 80240020 AC220E90 */  sw        $v0, %lo(D_80240E90_AF87E0)($at)
/* AF7974 80240024 0C0B1EAF */  jal       get_variable
/* AF7978 80240028 34A58892 */   ori      $a1, $a1, 0x8892
/* AF797C 8024002C 0040182D */  daddu     $v1, $v0, $zero
/* AF7980 80240030 24020001 */  addiu     $v0, $zero, 1
/* AF7984 80240034 14620006 */  bne       $v1, $v0, .L80240050
/* AF7988 80240038 24020005 */   addiu    $v0, $zero, 5
/* AF798C 8024003C 3C018024 */  lui       $at, %hi(D_80240E88_AF87D8)
/* AF7990 80240040 AC230E88 */  sw        $v1, %lo(D_80240E88_AF87D8)($at)
/* AF7994 80240044 3C018024 */  lui       $at, %hi(D_80240E8C_AF87DC)
/* AF7998 80240048 08090016 */  j         .L80240058
/* AF799C 8024004C AC220E8C */   sw       $v0, %lo(D_80240E8C_AF87DC)($at)
.L80240050:
/* AF79A0 80240050 3C018024 */  lui       $at, %hi(D_80240E88_AF87D8)
/* AF79A4 80240054 AC200E88 */  sw        $zero, %lo(D_80240E88_AF87D8)($at)
.L80240058:
/* AF79A8 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF79AC 8024005C 24020002 */  addiu     $v0, $zero, 2
/* AF79B0 80240060 03E00008 */  jr        $ra
/* AF79B4 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
