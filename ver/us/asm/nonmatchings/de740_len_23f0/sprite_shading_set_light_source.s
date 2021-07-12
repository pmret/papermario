.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sprite_shading_set_light_source
/* DE854 80148154 2C820007 */  sltiu     $v0, $a0, 7
/* DE858 80148158 44860000 */  mtc1      $a2, $f0
/* DE85C 8014815C 44871000 */  mtc1      $a3, $f2
/* DE860 80148160 8FA60014 */  lw        $a2, 0x14($sp)
/* DE864 80148164 8FA70018 */  lw        $a3, 0x18($sp)
/* DE868 80148168 8FA8001C */  lw        $t0, 0x1c($sp)
/* DE86C 8014816C 8FA90024 */  lw        $t1, 0x24($sp)
/* DE870 80148170 10400012 */  beqz      $v0, .L801481BC
/* DE874 80148174 00041040 */   sll      $v0, $a0, 1
/* DE878 80148178 00441021 */  addu      $v0, $v0, $a0
/* DE87C 8014817C 000210C0 */  sll       $v0, $v0, 3
/* DE880 80148180 3C038015 */  lui       $v1, %hi(D_80151328)
/* DE884 80148184 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* DE888 80148188 24420004 */  addiu     $v0, $v0, 4
/* DE88C 8014818C 00621821 */  addu      $v1, $v1, $v0
/* DE890 80148190 A0650000 */  sb        $a1, ($v1)
/* DE894 80148194 E4600004 */  swc1      $f0, 4($v1)
/* DE898 80148198 E4620008 */  swc1      $f2, 8($v1)
/* DE89C 8014819C C7A00010 */  lwc1      $f0, 0x10($sp)
/* DE8A0 801481A0 A0660001 */  sb        $a2, 1($v1)
/* DE8A4 801481A4 A0670002 */  sb        $a3, 2($v1)
/* DE8A8 801481A8 A0680003 */  sb        $t0, 3($v1)
/* DE8AC 801481AC E460000C */  swc1      $f0, 0xc($v1)
/* DE8B0 801481B0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* DE8B4 801481B4 A0690014 */  sb        $t1, 0x14($v1)
/* DE8B8 801481B8 E4600010 */  swc1      $f0, 0x10($v1)
.L801481BC:
/* DE8BC 801481BC 03E00008 */  jr        $ra
/* DE8C0 801481C0 00000000 */   nop
