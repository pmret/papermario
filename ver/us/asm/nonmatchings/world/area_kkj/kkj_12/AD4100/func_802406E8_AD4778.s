.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E8_AD4778
/* AD4778 802406E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AD477C 802406EC AFBF0010 */  sw        $ra, 0x10($sp)
/* AD4780 802406F0 8C82000C */  lw        $v0, 0xc($a0)
/* AD4784 802406F4 3C068011 */  lui       $a2, %hi(gPlayerStatus+0xC)
/* AD4788 802406F8 80C6EFD4 */  lb        $a2, %lo(gPlayerStatus+0xC)($a2)
/* AD478C 802406FC 0C0B2026 */  jal       evt_set_variable
/* AD4790 80240700 8C450000 */   lw       $a1, ($v0)
/* AD4794 80240704 8FBF0010 */  lw        $ra, 0x10($sp)
/* AD4798 80240708 24020002 */  addiu     $v0, $zero, 2
/* AD479C 8024070C 03E00008 */  jr        $ra
/* AD47A0 80240710 27BD0018 */   addiu    $sp, $sp, 0x18
