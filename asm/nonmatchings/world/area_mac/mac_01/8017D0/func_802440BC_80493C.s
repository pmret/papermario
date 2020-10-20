.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802440BC_80493C
/* 80493C 802440BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 804940 802440C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 804944 802440C4 0C00EABB */  jal       get_npc_unsafe
/* 804948 802440C8 8C84008C */   lw       $a0, 0x8c($a0)
/* 80494C 802440CC 3C038026 */  lui       $v1, 0x8026
/* 804950 802440D0 8C632C34 */  lw        $v1, 0x2c34($v1)
/* 804954 802440D4 AC430028 */  sw        $v1, 0x28($v0)
/* 804958 802440D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 80495C 802440DC 24020002 */  addiu     $v0, $zero, 2
/* 804960 802440E0 03E00008 */  jr        $ra
/* 804964 802440E4 27BD0018 */   addiu    $sp, $sp, 0x18
