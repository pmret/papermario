.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C4D3E0
/* C4D3E0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C4D3E4 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* C4D3E8 80240008 0000202D */  daddu     $a0, $zero, $zero
/* C4D3EC 8024000C 3C05FD05 */  lui       $a1, 0xfd05
/* C4D3F0 80240010 0C0B1EAF */  jal       get_variable
/* C4D3F4 80240014 34A50F80 */   ori      $a1, $a1, 0xf80
/* C4D3F8 80240018 0C04417A */  jal       get_entity_by_index
/* C4D3FC 8024001C 0040202D */   daddu    $a0, $v0, $zero
/* C4D400 80240020 50400007 */  beql      $v0, $zero, .L80240040
/* C4D404 80240024 0000102D */   daddu    $v0, $zero, $zero
/* C4D408 80240028 84440014 */  lh        $a0, 0x14($v0)
/* C4D40C 8024002C 3C050000 */  lui       $a1, 0
/* C4D410 80240030 24A501E4 */  addiu     $a1, $a1, 0x1e4
/* C4D414 80240034 0C048052 */  jal       play_model_animation
/* C4D418 80240038 00000000 */   nop      
/* C4D41C 8024003C 24020002 */  addiu     $v0, $zero, 2
.L80240040:
/* C4D420 80240040 8FBF0010 */  lw        $ra, 0x10($sp)
/* C4D424 80240044 03E00008 */  jr        $ra
/* C4D428 80240048 27BD0018 */   addiu    $sp, $sp, 0x18
/* C4D42C 8024004C 00000000 */  nop       
