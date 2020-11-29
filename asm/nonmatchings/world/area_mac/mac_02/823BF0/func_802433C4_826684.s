.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802433C4_826684
/* 826684 802433C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 826688 802433C8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 82668C 802433CC 0C00EABB */  jal       get_npc_unsafe
/* 826690 802433D0 8C84008C */   lw       $a0, 0x8c($a0)
/* 826694 802433D4 3C038025 */  lui       $v1, %hi(D_8024EA18)
/* 826698 802433D8 8C63EA18 */  lw        $v1, %lo(D_8024EA18)($v1)
/* 82669C 802433DC AC430028 */  sw        $v1, 0x28($v0)
/* 8266A0 802433E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8266A4 802433E4 24020002 */  addiu     $v0, $zero, 2
/* 8266A8 802433E8 03E00008 */  jr        $ra
/* 8266AC 802433EC 27BD0018 */   addiu    $sp, $sp, 0x18
