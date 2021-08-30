.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetMessageBoxDuration
/* 17FCE8 80251408 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17FCEC 8025140C AFBF0010 */  sw        $ra, 0x10($sp)
/* 17FCF0 80251410 8C82000C */  lw        $v0, 0xc($a0)
/* 17FCF4 80251414 0C0B1EAF */  jal       evt_get_variable
/* 17FCF8 80251418 8C450000 */   lw       $a1, ($v0)
/* 17FCFC 8025141C 0C093EB1 */  jal       btl_set_popup_duration
/* 17FD00 80251420 0040202D */   daddu    $a0, $v0, $zero
/* 17FD04 80251424 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17FD08 80251428 24020002 */  addiu     $v0, $zero, 2
/* 17FD0C 8025142C 03E00008 */  jr        $ra
/* 17FD10 80251430 27BD0018 */   addiu    $sp, $sp, 0x18
