.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242224_7ECF34
/* 7ECF34 80242224 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7ECF38 80242228 24020001 */  addiu     $v0, $zero, 1
/* 7ECF3C 8024222C AFBF0010 */  sw        $ra, 0x10($sp)
/* 7ECF40 80242230 3C018011 */  lui       $at, %hi(gPlayerData+0x2)
/* 7ECF44 80242234 A022F292 */  sb        $v0, %lo(gPlayerData+0x2)($at)
/* 7ECF48 80242238 0C03A6DB */  jal       sync_status_menu
/* 7ECF4C 8024223C 00000000 */   nop      
/* 7ECF50 80242240 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7ECF54 80242244 24020002 */  addiu     $v0, $zero, 2
/* 7ECF58 80242248 03E00008 */  jr        $ra
/* 7ECF5C 8024224C 27BD0018 */   addiu    $sp, $sp, 0x18
