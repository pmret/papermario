.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8012C9A8
/* C30A8 8012C9A8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C30AC 8012C9AC 308400FF */  andi      $a0, $a0, 0xff
/* C30B0 8012C9B0 30A500FF */  andi      $a1, $a1, 0xff
/* C30B4 8012C9B4 30C600FF */  andi      $a2, $a2, 0xff
/* C30B8 8012C9B8 8FA20038 */  lw        $v0, 0x38($sp)
/* C30BC 8012C9BC 8FA8003C */  lw        $t0, 0x3c($sp)
/* C30C0 8012C9C0 8FA30040 */  lw        $v1, 0x40($sp)
/* C30C4 8012C9C4 8FA90044 */  lw        $t1, 0x44($sp)
/* C30C8 8012C9C8 30E700FF */  andi      $a3, $a3, 0xff
/* C30CC 8012C9CC AFBF0020 */  sw        $ra, 0x20($sp)
/* C30D0 8012C9D0 00431821 */  addu      $v1, $v0, $v1
/* C30D4 8012C9D4 01094821 */  addu      $t1, $t0, $t1
/* C30D8 8012C9D8 3042FFFF */  andi      $v0, $v0, 0xffff
/* C30DC 8012C9DC 3108FFFF */  andi      $t0, $t0, 0xffff
/* C30E0 8012C9E0 3063FFFF */  andi      $v1, $v1, 0xffff
/* C30E4 8012C9E4 3129FFFF */  andi      $t1, $t1, 0xffff
/* C30E8 8012C9E8 AFA20010 */  sw        $v0, 0x10($sp)
/* C30EC 8012C9EC AFA80014 */  sw        $t0, 0x14($sp)
/* C30F0 8012C9F0 AFA30018 */  sw        $v1, 0x18($sp)
/* C30F4 8012C9F4 0C04B282 */  jal       func_8012CA08
/* C30F8 8012C9F8 AFA9001C */   sw       $t1, 0x1c($sp)
/* C30FC 8012C9FC 8FBF0020 */  lw        $ra, 0x20($sp)
/* C3100 8012CA00 03E00008 */  jr        $ra
/* C3104 8012CA04 27BD0028 */   addiu    $sp, $sp, 0x28
