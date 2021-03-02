.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801109DC
/* A70DC 801109DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A70E0 801109E0 AFB20018 */  sw        $s2, 0x18($sp)
/* A70E4 801109E4 0080902D */  daddu     $s2, $a0, $zero
/* A70E8 801109E8 AFB00010 */  sw        $s0, 0x10($sp)
/* A70EC 801109EC 0000802D */  daddu     $s0, $zero, $zero
/* A70F0 801109F0 AFBF001C */  sw        $ra, 0x1c($sp)
/* A70F4 801109F4 0C0441A9 */  jal       get_entity_type
/* A70F8 801109F8 AFB10014 */   sw       $s1, 0x14($sp)
/* A70FC 801109FC 0C039422 */  jal       get_current_partner_id
/* A7100 80110A00 0040882D */   daddu    $s1, $v0, $zero
/* A7104 80110A04 00021600 */  sll       $v0, $v0, 0x18
/* A7108 80110A08 00021E03 */  sra       $v1, $v0, 0x18
/* A710C 80110A0C 24020002 */  addiu     $v0, $zero, 2
/* A7110 80110A10 1062000C */  beq       $v1, $v0, .L80110A44
/* A7114 80110A14 24020003 */   addiu    $v0, $zero, 3
/* A7118 80110A18 1462001E */  bne       $v1, $v0, .L80110A94
/* A711C 80110A1C 0200102D */   daddu    $v0, $s0, $zero
/* A7120 80110A20 2623FFF9 */  addiu     $v1, $s1, -7
/* A7124 80110A24 2C620020 */  sltiu     $v0, $v1, 0x20
/* A7128 80110A28 1040000F */  beqz      $v0, L80110A68_A7168
/* A712C 80110A2C 00031080 */   sll      $v0, $v1, 2
/* A7130 80110A30 3C018015 */  lui       $at, %hi(jtbl_8014F768)
/* A7134 80110A34 00220821 */  addu      $at, $at, $v0
/* A7138 80110A38 8C22F768 */  lw        $v0, %lo(jtbl_8014F768)($at)
/* A713C 80110A3C 00400008 */  jr        $v0
/* A7140 80110A40 00000000 */   nop
.L80110A44:
/* A7144 80110A44 2623FFF9 */  addiu     $v1, $s1, -7
/* A7148 80110A48 2C62001C */  sltiu     $v0, $v1, 0x1c
/* A714C 80110A4C 10400006 */  beqz      $v0, L80110A68_A7168
/* A7150 80110A50 00031080 */   sll      $v0, $v1, 2
/* A7154 80110A54 3C018015 */  lui       $at, %hi(jtbl_8014F7E8)
/* A7158 80110A58 00220821 */  addu      $at, $at, $v0
/* A715C 80110A5C 8C22F7E8 */  lw        $v0, %lo(jtbl_8014F7E8)($at)
/* A7160 80110A60 00400008 */  jr        $v0
/* A7164 80110A64 00000000 */   nop
glabel L80110A68_A7168
/* A7168 80110A68 080442A5 */  j         .L80110A94
/* A716C 80110A6C 0000102D */   daddu    $v0, $zero, $zero
glabel L80110A70_A7170
/* A7170 80110A70 0C04417A */  jal       get_entity_by_index
/* A7174 80110A74 0240202D */   daddu    $a0, $s2, $zero
/* A7178 80110A78 0040202D */  daddu     $a0, $v0, $zero
/* A717C 80110A7C 24100001 */  addiu     $s0, $zero, 1
/* A7180 80110A80 8C820000 */  lw        $v0, ($a0)
/* A7184 80110A84 3C030002 */  lui       $v1, 2
/* A7188 80110A88 00431025 */  or        $v0, $v0, $v1
/* A718C 80110A8C AC820000 */  sw        $v0, ($a0)
/* A7190 80110A90 0200102D */  daddu     $v0, $s0, $zero
.L80110A94:
/* A7194 80110A94 8FBF001C */  lw        $ra, 0x1c($sp)
/* A7198 80110A98 8FB20018 */  lw        $s2, 0x18($sp)
/* A719C 80110A9C 8FB10014 */  lw        $s1, 0x14($sp)
/* A71A0 80110AA0 8FB00010 */  lw        $s0, 0x10($sp)
/* A71A4 80110AA4 03E00008 */  jr        $ra
/* A71A8 80110AA8 27BD0020 */   addiu    $sp, $sp, 0x20
