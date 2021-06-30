.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240010_90B250
/* 90B250 80240010 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 90B254 80240014 AFB00018 */  sw        $s0, 0x18($sp)
/* 90B258 80240018 0080802D */  daddu     $s0, $a0, $zero
/* 90B25C 8024001C 10A00004 */  beqz      $a1, .L80240030
/* 90B260 80240020 AFBF001C */   sw       $ra, 0x1c($sp)
/* 90B264 80240024 0C04E0A8 */  jal       set_map_transition_effect
/* 90B268 80240028 24040004 */   addiu    $a0, $zero, 4
/* 90B26C 8024002C AE000074 */  sw        $zero, 0x74($s0)
.L80240030:
/* 90B270 80240030 96020076 */  lhu       $v0, 0x76($s0)
/* 90B274 80240034 27A40010 */  addiu     $a0, $sp, 0x10
/* 90B278 80240038 0C04E0AB */  jal       update_exit_map_screen_overlay
/* 90B27C 8024003C A7A20010 */   sh       $v0, 0x10($sp)
/* 90B280 80240040 00021400 */  sll       $v0, $v0, 0x10
/* 90B284 80240044 10400005 */  beqz      $v0, .L8024005C
/* 90B288 80240048 0000102D */   daddu    $v0, $zero, $zero
/* 90B28C 8024004C 0C00CD3C */  jal       set_game_mode
/* 90B290 80240050 0000202D */   daddu    $a0, $zero, $zero
/* 90B294 80240054 08090019 */  j         .L80240064
/* 90B298 80240058 24020002 */   addiu    $v0, $zero, 2
.L8024005C:
/* 90B29C 8024005C 87A30010 */  lh        $v1, 0x10($sp)
/* 90B2A0 80240060 AE030074 */  sw        $v1, 0x74($s0)
.L80240064:
/* 90B2A4 80240064 8FBF001C */  lw        $ra, 0x1c($sp)
/* 90B2A8 80240068 8FB00018 */  lw        $s0, 0x18($sp)
/* 90B2AC 8024006C 03E00008 */  jr        $ra
/* 90B2B0 80240070 27BD0020 */   addiu    $sp, $sp, 0x20
