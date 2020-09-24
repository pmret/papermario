.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel DisablePartnerBlur
/* 173FB8 802456D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 173FBC 802456DC AFBF0010 */  sw        $ra, 0x10($sp)
/* 173FC0 802456E0 0C09519A */  jal       disable_partner_blur
/* 173FC4 802456E4 00000000 */   nop      
/* 173FC8 802456E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 173FCC 802456EC 24020002 */  addiu     $v0, $zero, 2
/* 173FD0 802456F0 03E00008 */  jr        $ra
/* 173FD4 802456F4 27BD0018 */   addiu    $sp, $sp, 0x18
