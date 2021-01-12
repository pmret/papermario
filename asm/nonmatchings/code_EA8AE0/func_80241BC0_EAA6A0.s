.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BC0_EAA6A0
/* EAA6A0 80241BC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EAA6A4 80241BC4 AFB10014 */  sw        $s1, 0x14($sp)
/* EAA6A8 80241BC8 0080882D */  daddu     $s1, $a0, $zero
/* EAA6AC 80241BCC AFBF0018 */  sw        $ra, 0x18($sp)
/* EAA6B0 80241BD0 AFB00010 */  sw        $s0, 0x10($sp)
/* EAA6B4 80241BD4 8E30000C */  lw        $s0, 0xc($s1)
/* EAA6B8 80241BD8 8E050000 */  lw        $a1, ($s0)
/* EAA6BC 80241BDC 0C0B53A3 */  jal       func_802D4E8C
/* EAA6C0 80241BE0 26100004 */   addiu    $s0, $s0, 4
/* EAA6C4 80241BE4 0220202D */  daddu     $a0, $s1, $zero
/* EAA6C8 80241BE8 8E050000 */  lw        $a1, ($s0)
/* EAA6CC 80241BEC 0C0B53A3 */  jal       func_802D4E8C
/* EAA6D0 80241BF0 0040802D */   daddu    $s0, $v0, $zero
/* EAA6D4 80241BF4 0040202D */  daddu     $a0, $v0, $zero
/* EAA6D8 80241BF8 24020001 */  addiu     $v0, $zero, 1
/* EAA6DC 80241BFC 12020019 */  beq       $s0, $v0, .L80241C64
/* EAA6E0 80241C00 2A020002 */   slti     $v0, $s0, 2
/* EAA6E4 80241C04 10400005 */  beqz      $v0, .L80241C1C
/* EAA6E8 80241C08 24020002 */   addiu    $v0, $zero, 2
/* EAA6EC 80241C0C 12000009 */  beqz      $s0, .L80241C34
/* EAA6F0 80241C10 00041840 */   sll      $v1, $a0, 1
/* EAA6F4 80241C14 08090743 */  j         .L80241D0C
/* EAA6F8 80241C18 00000000 */   nop
.L80241C1C:
/* EAA6FC 80241C1C 1202001F */  beq       $s0, $v0, .L80241C9C
/* EAA700 80241C20 24020003 */   addiu    $v0, $zero, 3
/* EAA704 80241C24 1202002B */  beq       $s0, $v0, .L80241CD4
/* EAA708 80241C28 3C068020 */   lui      $a2, 0x8020
/* EAA70C 80241C2C 08090743 */  j         .L80241D0C
/* EAA710 80241C30 00000000 */   nop
.L80241C34:
/* EAA714 80241C34 3C028024 */  lui       $v0, %hi(D_80243BB8)
/* EAA718 80241C38 24423BB8 */  addiu     $v0, $v0, %lo(D_80243BB8)
/* EAA71C 80241C3C 00641821 */  addu      $v1, $v1, $a0
/* EAA720 80241C40 00032080 */  sll       $a0, $v1, 2
/* EAA724 80241C44 00822021 */  addu      $a0, $a0, $v0
/* EAA728 80241C48 24630001 */  addiu     $v1, $v1, 1
/* EAA72C 80241C4C 00031880 */  sll       $v1, $v1, 2
/* EAA730 80241C50 00621821 */  addu      $v1, $v1, $v0
/* EAA734 80241C54 8C840000 */  lw        $a0, ($a0)
/* EAA738 80241C58 8C650000 */  lw        $a1, ($v1)
/* EAA73C 80241C5C 08090741 */  j         .L80241D04
/* EAA740 80241C60 3C068020 */   lui      $a2, 0x8020
.L80241C64:
/* EAA744 80241C64 3C068020 */  lui       $a2, 0x8020
/* EAA748 80241C68 3C028024 */  lui       $v0, %hi(D_80243BB8)
/* EAA74C 80241C6C 24423BB8 */  addiu     $v0, $v0, %lo(D_80243BB8)
/* EAA750 80241C70 00041840 */  sll       $v1, $a0, 1
/* EAA754 80241C74 00641821 */  addu      $v1, $v1, $a0
/* EAA758 80241C78 00032080 */  sll       $a0, $v1, 2
/* EAA75C 80241C7C 00822021 */  addu      $a0, $a0, $v0
/* EAA760 80241C80 24630001 */  addiu     $v1, $v1, 1
/* EAA764 80241C84 00031880 */  sll       $v1, $v1, 2
/* EAA768 80241C88 00621821 */  addu      $v1, $v1, $v0
/* EAA76C 80241C8C 8C840000 */  lw        $a0, ($a0)
/* EAA770 80241C90 8C650000 */  lw        $a1, ($v1)
/* EAA774 80241C94 08090741 */  j         .L80241D04
/* EAA778 80241C98 34C64000 */   ori      $a2, $a2, 0x4000
.L80241C9C:
/* EAA77C 80241C9C 3C068020 */  lui       $a2, 0x8020
/* EAA780 80241CA0 3C028024 */  lui       $v0, %hi(D_80243BB8)
/* EAA784 80241CA4 24423BB8 */  addiu     $v0, $v0, %lo(D_80243BB8)
/* EAA788 80241CA8 00041840 */  sll       $v1, $a0, 1
/* EAA78C 80241CAC 00641821 */  addu      $v1, $v1, $a0
/* EAA790 80241CB0 00032080 */  sll       $a0, $v1, 2
/* EAA794 80241CB4 00822021 */  addu      $a0, $a0, $v0
/* EAA798 80241CB8 24630001 */  addiu     $v1, $v1, 1
/* EAA79C 80241CBC 00031880 */  sll       $v1, $v1, 2
/* EAA7A0 80241CC0 00621821 */  addu      $v1, $v1, $v0
/* EAA7A4 80241CC4 8C840000 */  lw        $a0, ($a0)
/* EAA7A8 80241CC8 8C650000 */  lw        $a1, ($v1)
/* EAA7AC 80241CCC 08090741 */  j         .L80241D04
/* EAA7B0 80241CD0 34C67000 */   ori      $a2, $a2, 0x7000
.L80241CD4:
/* EAA7B4 80241CD4 3C028024 */  lui       $v0, %hi(D_80243BB8)
/* EAA7B8 80241CD8 24423BB8 */  addiu     $v0, $v0, %lo(D_80243BB8)
/* EAA7BC 80241CDC 00041840 */  sll       $v1, $a0, 1
/* EAA7C0 80241CE0 00641821 */  addu      $v1, $v1, $a0
/* EAA7C4 80241CE4 00032080 */  sll       $a0, $v1, 2
/* EAA7C8 80241CE8 00822021 */  addu      $a0, $a0, $v0
/* EAA7CC 80241CEC 24630001 */  addiu     $v1, $v1, 1
/* EAA7D0 80241CF0 00031880 */  sll       $v1, $v1, 2
/* EAA7D4 80241CF4 00621821 */  addu      $v1, $v1, $v0
/* EAA7D8 80241CF8 8C840000 */  lw        $a0, ($a0)
/* EAA7DC 80241CFC 8C650000 */  lw        $a1, ($v1)
/* EAA7E0 80241D00 34C6A000 */  ori       $a2, $a2, 0xa000
.L80241D04:
/* EAA7E4 80241D04 0C00AA8B */  jal       func_8002AA2C
/* EAA7E8 80241D08 00000000 */   nop
.L80241D0C:
/* EAA7EC 80241D0C 8FBF0018 */  lw        $ra, 0x18($sp)
/* EAA7F0 80241D10 8FB10014 */  lw        $s1, 0x14($sp)
/* EAA7F4 80241D14 8FB00010 */  lw        $s0, 0x10($sp)
/* EAA7F8 80241D18 24020002 */  addiu     $v0, $zero, 2
/* EAA7FC 80241D1C 03E00008 */  jr        $ra
/* EAA800 80241D20 27BD0020 */   addiu    $sp, $sp, 0x20
/* EAA804 80241D24 00000000 */  nop
/* EAA808 80241D28 00000000 */  nop
/* EAA80C 80241D2C 00000000 */  nop
