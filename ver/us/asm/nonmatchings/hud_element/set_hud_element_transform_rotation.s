.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_hud_element_transform_rotation
/* DB924 80145224 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB928 80145228 00822024 */  and       $a0, $a0, $v0
/* DB92C 8014522C 00042080 */  sll       $a0, $a0, 2
/* DB930 80145230 3C030001 */  lui       $v1, 1
/* DB934 80145234 3C028015 */  lui       $v0, %hi(gHudElementList)
/* DB938 80145238 8C427960 */  lw        $v0, %lo(gHudElementList)($v0)
/* DB93C 8014523C 44850000 */  mtc1      $a1, $f0
/* DB940 80145240 00822021 */  addu      $a0, $a0, $v0
/* DB944 80145244 8C840000 */  lw        $a0, ($a0)
/* DB948 80145248 44861000 */  mtc1      $a2, $f2
/* DB94C 8014524C 8C820000 */  lw        $v0, ($a0)
/* DB950 80145250 44872000 */  mtc1      $a3, $f4
/* DB954 80145254 00431024 */  and       $v0, $v0, $v1
/* DB958 80145258 10400004 */  beqz      $v0, .L8014526C
/* DB95C 8014525C 8C83001C */   lw       $v1, 0x1c($a0)
/* DB960 80145260 E4600010 */  swc1      $f0, 0x10($v1)
/* DB964 80145264 E4620014 */  swc1      $f2, 0x14($v1)
/* DB968 80145268 E4640018 */  swc1      $f4, 0x18($v1)
.L8014526C:
/* DB96C 8014526C 03E00008 */  jr        $ra
/* DB970 80145270 00000000 */   nop
