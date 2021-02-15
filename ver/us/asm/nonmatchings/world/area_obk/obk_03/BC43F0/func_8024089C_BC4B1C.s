.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024089C_BC4B1C
/* BC4B1C 8024089C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC4B20 802408A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* BC4B24 802408A4 0C00EABB */  jal       get_npc_unsafe
/* BC4B28 802408A8 8C84008C */   lw       $a0, 0x8c($a0)
/* BC4B2C 802408AC 3C038024 */  lui       $v1, %hi(D_80243DA4)
/* BC4B30 802408B0 8C633DA4 */  lw        $v1, %lo(D_80243DA4)($v1)
/* BC4B34 802408B4 AC430028 */  sw        $v1, 0x28($v0)
/* BC4B38 802408B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* BC4B3C 802408BC 24020002 */  addiu     $v0, $zero, 2
/* BC4B40 802408C0 03E00008 */  jr        $ra
/* BC4B44 802408C4 27BD0018 */   addiu    $sp, $sp, 0x18
/* BC4B48 802408C8 00000000 */  nop
/* BC4B4C 802408CC 00000000 */  nop
