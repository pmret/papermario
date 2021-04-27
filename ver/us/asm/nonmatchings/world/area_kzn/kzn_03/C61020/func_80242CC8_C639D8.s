.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242CC8_C639D8
/* C639D8 80242CC8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C639DC 80242CCC AFBF0010 */  sw        $ra, 0x10($sp)
/* C639E0 80242CD0 0C00EABB */  jal       get_npc_unsafe
/* C639E4 80242CD4 8C84008C */   lw       $a0, 0x8c($a0)
/* C639E8 80242CD8 3C038024 */  lui       $v1, %hi(dro_02_pad_XX111)
/* C639EC 80242CDC 8C6375E4 */  lw        $v1, %lo(dro_02_pad_XX111)($v1)
/* C639F0 80242CE0 AC430028 */  sw        $v1, 0x28($v0)
/* C639F4 80242CE4 8FBF0010 */  lw        $ra, 0x10($sp)
/* C639F8 80242CE8 24020002 */  addiu     $v0, $zero, 2
/* C639FC 80242CEC 03E00008 */  jr        $ra
/* C63A00 80242CF0 27BD0018 */   addiu    $sp, $sp, 0x18
/* C63A04 80242CF4 00000000 */  nop
/* C63A08 80242CF8 00000000 */  nop
/* C63A0C 80242CFC 00000000 */  nop
