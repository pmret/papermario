.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406F8
/* AB06E8 802406F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AB06EC 802406FC AFBF0010 */  sw        $ra, 0x10($sp)
/* AB06F0 80240700 8C82000C */  lw        $v0, 0xc($a0)
/* AB06F4 80240704 0C0B1EAF */  jal       get_variable
/* AB06F8 80240708 8C450000 */   lw       $a1, ($v0)
/* AB06FC 8024070C 3C018024 */  lui       $at, 0x8024
/* AB0700 80240710 AC221220 */  sw        $v0, 0x1220($at)
/* AB0704 80240714 24020002 */  addiu     $v0, $zero, 2
/* AB0708 80240718 8FBF0010 */  lw        $ra, 0x10($sp)
/* AB070C 8024071C 24030001 */  addiu     $v1, $zero, 1
/* AB0710 80240720 3C018024 */  lui       $at, 0x8024
/* AB0714 80240724 AC23121C */  sw        $v1, 0x121c($at)
/* AB0718 80240728 03E00008 */  jr        $ra
/* AB071C 8024072C 27BD0018 */   addiu    $sp, $sp, 0x18
