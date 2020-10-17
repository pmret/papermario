.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel bind_dynamic_entity_3
/* B9858 80123158 3C038015 */  lui       $v1, %hi(gCurrentDynamicEntityListPtr)
/* B985C 8012315C 8C634420 */  lw        $v1, %lo(gCurrentDynamicEntityListPtr)($v1)
/* B9860 80123160 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B9864 80123164 AFB10014 */  sw        $s1, 0x14($sp)
/* B9868 80123168 0080882D */  daddu     $s1, $a0, $zero
/* B986C 8012316C AFB20018 */  sw        $s2, 0x18($sp)
/* B9870 80123170 00A0902D */  daddu     $s2, $a1, $zero
/* B9874 80123174 AFB00010 */  sw        $s0, 0x10($sp)
/* B9878 80123178 0000802D */  daddu     $s0, $zero, $zero
/* B987C 8012317C AFBF001C */  sw        $ra, 0x1c($sp)
.L80123180:
/* B9880 80123180 8C620000 */  lw        $v0, ($v1)
/* B9884 80123184 10400006 */  beqz      $v0, .L801231A0
/* B9888 80123188 2A020010 */   slti     $v0, $s0, 0x10
/* B988C 8012318C 26100001 */  addiu     $s0, $s0, 1
/* B9890 80123190 2A020010 */  slti      $v0, $s0, 0x10
/* B9894 80123194 1440FFFA */  bnez      $v0, .L80123180
/* B9898 80123198 24630004 */   addiu    $v1, $v1, 4
/* B989C 8012319C 2A020010 */  slti      $v0, $s0, 0x10
.L801231A0:
/* B98A0 801231A0 14400003 */  bnez      $v0, .L801231B0
/* B98A4 801231A4 00000000 */   nop      
.L801231A8:
/* B98A8 801231A8 08048C6A */  j         .L801231A8
/* B98AC 801231AC 00000000 */   nop      
.L801231B0:
/* B98B0 801231B0 0C00AB39 */  jal       heap_malloc
/* B98B4 801231B4 2404000C */   addiu    $a0, $zero, 0xc
/* B98B8 801231B8 3C048015 */  lui       $a0, %hi(gCurrentDynamicEntityListPtr)
/* B98BC 801231BC 8C844420 */  lw        $a0, %lo(gCurrentDynamicEntityListPtr)($a0)
/* B98C0 801231C0 00101880 */  sll       $v1, $s0, 2
/* B98C4 801231C4 00641821 */  addu      $v1, $v1, $a0
/* B98C8 801231C8 0040202D */  daddu     $a0, $v0, $zero
/* B98CC 801231CC 14800003 */  bnez      $a0, .L801231DC
/* B98D0 801231D0 AC640000 */   sw       $a0, ($v1)
.L801231D4:
/* B98D4 801231D4 08048C75 */  j         .L801231D4
/* B98D8 801231D8 00000000 */   nop      
.L801231DC:
/* B98DC 801231DC 24020003 */  addiu     $v0, $zero, 3
/* B98E0 801231E0 AC820000 */  sw        $v0, ($a0)
/* B98E4 801231E4 16200004 */  bnez      $s1, .L801231F8
/* B98E8 801231E8 AC910004 */   sw       $s1, 4($a0)
/* B98EC 801231EC 3C028012 */  lui       $v0, %hi(stub_dynamic_entity_delegate)
/* B98F0 801231F0 244230B0 */  addiu     $v0, $v0, %lo(stub_dynamic_entity_delegate)
/* B98F4 801231F4 AC820004 */  sw        $v0, 4($a0)
.L801231F8:
/* B98F8 801231F8 16400004 */  bnez      $s2, .L8012320C
/* B98FC 801231FC AC920008 */   sw       $s2, 8($a0)
/* B9900 80123200 3C028012 */  lui       $v0, %hi(stub_dynamic_entity_delegate)
/* B9904 80123204 244230B0 */  addiu     $v0, $v0, %lo(stub_dynamic_entity_delegate)
/* B9908 80123208 AC820008 */  sw        $v0, 8($a0)
.L8012320C:
/* B990C 8012320C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B9910 80123210 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B9914 80123214 80420070 */  lb        $v0, 0x70($v0)
/* B9918 80123218 54400001 */  bnel      $v0, $zero, .L80123220
/* B991C 8012321C 36100800 */   ori      $s0, $s0, 0x800
.L80123220:
/* B9920 80123220 0200102D */  daddu     $v0, $s0, $zero
/* B9924 80123224 8FBF001C */  lw        $ra, 0x1c($sp)
/* B9928 80123228 8FB20018 */  lw        $s2, 0x18($sp)
/* B992C 8012322C 8FB10014 */  lw        $s1, 0x14($sp)
/* B9930 80123230 8FB00010 */  lw        $s0, 0x10($sp)
/* B9934 80123234 03E00008 */  jr        $ra
/* B9938 80123238 27BD0020 */   addiu    $sp, $sp, 0x20
