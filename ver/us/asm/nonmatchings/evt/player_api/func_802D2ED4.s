.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2ED4
/* F7884 802D2ED4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* F7888 802D2ED8 308400FF */  andi      $a0, $a0, 0xff
/* F788C 802D2EDC 30A500FF */  andi      $a1, $a1, 0xff
/* F7890 802D2EE0 30C600FF */  andi      $a2, $a2, 0xff
/* F7894 802D2EE4 8FA20038 */  lw        $v0, 0x38($sp)
/* F7898 802D2EE8 8FA8003C */  lw        $t0, 0x3c($sp)
/* F789C 802D2EEC 8FA30040 */  lw        $v1, 0x40($sp)
/* F78A0 802D2EF0 8FA90044 */  lw        $t1, 0x44($sp)
/* F78A4 802D2EF4 30E700FF */  andi      $a3, $a3, 0xff
/* F78A8 802D2EF8 AFBF0020 */  sw        $ra, 0x20($sp)
/* F78AC 802D2EFC 00431821 */  addu      $v1, $v0, $v1
/* F78B0 802D2F00 01094821 */  addu      $t1, $t0, $t1
/* F78B4 802D2F04 3042FFFF */  andi      $v0, $v0, 0xffff
/* F78B8 802D2F08 3108FFFF */  andi      $t0, $t0, 0xffff
/* F78BC 802D2F0C 3063FFFF */  andi      $v1, $v1, 0xffff
/* F78C0 802D2F10 3129FFFF */  andi      $t1, $t1, 0xffff
/* F78C4 802D2F14 AFA20010 */  sw        $v0, 0x10($sp)
/* F78C8 802D2F18 AFA80014 */  sw        $t0, 0x14($sp)
/* F78CC 802D2F1C AFA30018 */  sw        $v1, 0x18($sp)
/* F78D0 802D2F20 0C0B4B4C */  jal       func_802D2D30
/* F78D4 802D2F24 AFA9001C */   sw       $t1, 0x1c($sp)
/* F78D8 802D2F28 8FBF0020 */  lw        $ra, 0x20($sp)
/* F78DC 802D2F2C 03E00008 */  jr        $ra
/* F78E0 802D2F30 27BD0028 */   addiu    $sp, $sp, 0x28
