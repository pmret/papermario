.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800337E4
/* EBE4 800337E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EBE8 800337E8 AFBF0010 */  sw        $ra, 0x10($sp)
/* EBEC 800337EC 0C00F89C */  jal       func_8003E270
/* EBF0 800337F0 00000000 */   nop
/* EBF4 800337F4 3C02800A */  lui       $v0, %hi(D_8009E710)
/* EBF8 800337F8 8042E710 */  lb        $v0, %lo(D_8009E710)($v0)
/* EBFC 800337FC 04410003 */  bgez      $v0, .L8003380C
/* EC00 80033800 00000000 */   nop
/* EC04 80033804 0C08FA9F */  jal       func_8023EA7C
/* EC08 80033808 00000000 */   nop
.L8003380C:
/* EC0C 8003380C 8FBF0010 */  lw        $ra, 0x10($sp)
/* EC10 80033810 03E00008 */  jr        $ra
/* EC14 80033814 27BD0018 */   addiu    $sp, $sp, 0x18
