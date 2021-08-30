.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407C0_A0C4B0
/* A0C4B0 802407C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A0C4B4 802407C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* A0C4B8 802407C8 8C82000C */  lw        $v0, 0xc($a0)
/* A0C4BC 802407CC 0C0B1EAF */  jal       evt_get_variable
/* A0C4C0 802407D0 8C450000 */   lw       $a1, ($v0)
/* A0C4C4 802407D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* A0C4C8 802407D8 3C018011 */  lui       $at, %hi(gPlayerData+0x12)
/* A0C4CC 802407DC A022F2A2 */  sb        $v0, %lo(gPlayerData+0x12)($at)
/* A0C4D0 802407E0 24020002 */  addiu     $v0, $zero, 2
/* A0C4D4 802407E4 03E00008 */  jr        $ra
/* A0C4D8 802407E8 27BD0018 */   addiu    $sp, $sp, 0x18
/* A0C4DC 802407EC 00000000 */  nop
