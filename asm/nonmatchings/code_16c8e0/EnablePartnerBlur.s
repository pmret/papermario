.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel EnablePartnerBlur
/* 173F98 802456B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 173F9C 802456BC AFBF0010 */  sw        $ra, 0x10($sp)
/* 173FA0 802456C0 0C095191 */  jal       enable_partner_blur
/* 173FA4 802456C4 00000000 */   nop      
/* 173FA8 802456C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 173FAC 802456CC 24020002 */  addiu     $v0, $zero, 2
/* 173FB0 802456D0 03E00008 */  jr        $ra
/* 173FB4 802456D4 27BD0018 */   addiu    $sp, $sp, 0x18
