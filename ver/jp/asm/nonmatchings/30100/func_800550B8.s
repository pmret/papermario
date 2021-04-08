.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800550B8
/* 304B8 800550B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 304BC 800550BC 0080182D */  daddu     $v1, $a0, $zero
/* 304C0 800550C0 30E700FF */  andi      $a3, $a3, 0xff
/* 304C4 800550C4 00051400 */  sll       $v0, $a1, 0x10
/* 304C8 800550C8 AFA70010 */  sw        $a3, 0x10($sp)
/* 304CC 800550CC 00063C00 */  sll       $a3, $a2, 0x10
/* 304D0 800550D0 0060282D */  daddu     $a1, $v1, $zero
/* 304D4 800550D4 00023403 */  sra       $a2, $v0, 0x10
/* 304D8 800550D8 3C04800A */  lui       $a0, %hi(D_8009A620)
/* 304DC 800550DC 8C84A620 */  lw        $a0, %lo(D_8009A620)($a0)
/* 304E0 800550E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 304E4 800550E4 0C012CE2 */  jal       func_8004B388
/* 304E8 800550E8 00073C03 */   sra      $a3, $a3, 0x10
/* 304EC 800550EC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 304F0 800550F0 03E00008 */  jr        $ra
/* 304F4 800550F4 27BD0020 */   addiu    $sp, $sp, 0x20
