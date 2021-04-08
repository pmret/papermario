.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422B4_EE8864
/* EE8864 802422B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE8868 802422B8 AFBF0010 */  sw        $ra, 0x10($sp)
/* EE886C 802422BC 8C82000C */  lw        $v0, 0xc($a0)
/* EE8870 802422C0 0C0B53A3 */  jal       dead_get_variable
/* EE8874 802422C4 8C450000 */   lw       $a1, ($v0)
/* EE8878 802422C8 3C018024 */  lui       $at, %hi(D_80244630_EEABE0)
/* EE887C 802422CC AC224630 */  sw        $v0, %lo(D_80244630_EEABE0)($at)
/* EE8880 802422D0 24020002 */  addiu     $v0, $zero, 2
/* EE8884 802422D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* EE8888 802422D8 24030001 */  addiu     $v1, $zero, 1
/* EE888C 802422DC 3C018024 */  lui       $at, %hi(D_8024462C_EEABDC)
/* EE8890 802422E0 AC23462C */  sw        $v1, %lo(D_8024462C_EEABDC)($at)
/* EE8894 802422E4 03E00008 */  jr        $ra
/* EE8898 802422E8 27BD0018 */   addiu    $sp, $sp, 0x18
