.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245794_A2F9D4
/* A2F9D4 80245794 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2F9D8 80245798 AFBF0010 */  sw        $ra, 0x10($sp)
/* A2F9DC 8024579C 8C82000C */  lw        $v0, 0xc($a0)
/* A2F9E0 802457A0 0C0B1EAF */  jal       get_variable
/* A2F9E4 802457A4 8C450000 */   lw       $a1, ($v0)
/* A2F9E8 802457A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2F9EC 802457AC 3C018025 */  lui       $at, %hi(D_8024DCD0_A37F10)
/* A2F9F0 802457B0 AC22DCD0 */  sw        $v0, %lo(D_8024DCD0_A37F10)($at)
/* A2F9F4 802457B4 24020002 */  addiu     $v0, $zero, 2
/* A2F9F8 802457B8 03E00008 */  jr        $ra
/* A2F9FC 802457BC 27BD0018 */   addiu    $sp, $sp, 0x18
