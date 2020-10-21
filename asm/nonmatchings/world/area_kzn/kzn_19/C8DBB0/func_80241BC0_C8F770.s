.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BC0_C8F770
/* C8F770 80241BC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C8F774 80241BC4 AFB10014 */  sw        $s1, 0x14($sp)
/* C8F778 80241BC8 0080882D */  daddu     $s1, $a0, $zero
/* C8F77C 80241BCC AFBF0018 */  sw        $ra, 0x18($sp)
/* C8F780 80241BD0 AFB00010 */  sw        $s0, 0x10($sp)
/* C8F784 80241BD4 8E30000C */  lw        $s0, 0xc($s1)
/* C8F788 80241BD8 8E050000 */  lw        $a1, ($s0)
/* C8F78C 80241BDC 0C0B1EAF */  jal       get_variable
/* C8F790 80241BE0 26100004 */   addiu    $s0, $s0, 4
/* C8F794 80241BE4 0220202D */  daddu     $a0, $s1, $zero
/* C8F798 80241BE8 8E050000 */  lw        $a1, ($s0)
/* C8F79C 80241BEC 0C0B1EAF */  jal       get_variable
/* C8F7A0 80241BF0 0040802D */   daddu    $s0, $v0, $zero
/* C8F7A4 80241BF4 0040202D */  daddu     $a0, $v0, $zero
/* C8F7A8 80241BF8 24020001 */  addiu     $v0, $zero, 1
/* C8F7AC 80241BFC 12020019 */  beq       $s0, $v0, .L80241C64
/* C8F7B0 80241C00 2A020002 */   slti     $v0, $s0, 2
/* C8F7B4 80241C04 10400005 */  beqz      $v0, .L80241C1C
/* C8F7B8 80241C08 24020002 */   addiu    $v0, $zero, 2
/* C8F7BC 80241C0C 12000009 */  beqz      $s0, .L80241C34
/* C8F7C0 80241C10 00041840 */   sll      $v1, $a0, 1
/* C8F7C4 80241C14 08090743 */  j         .L80241D0C
/* C8F7C8 80241C18 00000000 */   nop      
.L80241C1C:
/* C8F7CC 80241C1C 1202001F */  beq       $s0, $v0, .L80241C9C
/* C8F7D0 80241C20 24020003 */   addiu    $v0, $zero, 3
/* C8F7D4 80241C24 1202002B */  beq       $s0, $v0, .L80241CD4
/* C8F7D8 80241C28 3C068020 */   lui      $a2, 0x8020
/* C8F7DC 80241C2C 08090743 */  j         .L80241D0C
/* C8F7E0 80241C30 00000000 */   nop      
.L80241C34:
/* C8F7E4 80241C34 3C028024 */  lui       $v0, 0x8024
/* C8F7E8 80241C38 24423BB8 */  addiu     $v0, $v0, 0x3bb8
/* C8F7EC 80241C3C 00641821 */  addu      $v1, $v1, $a0
/* C8F7F0 80241C40 00032080 */  sll       $a0, $v1, 2
/* C8F7F4 80241C44 00822021 */  addu      $a0, $a0, $v0
/* C8F7F8 80241C48 24630001 */  addiu     $v1, $v1, 1
/* C8F7FC 80241C4C 00031880 */  sll       $v1, $v1, 2
/* C8F800 80241C50 00621821 */  addu      $v1, $v1, $v0
/* C8F804 80241C54 8C840000 */  lw        $a0, ($a0)
/* C8F808 80241C58 8C650000 */  lw        $a1, ($v1)
/* C8F80C 80241C5C 08090741 */  j         .L80241D04
/* C8F810 80241C60 3C068020 */   lui      $a2, 0x8020
.L80241C64:
/* C8F814 80241C64 3C068020 */  lui       $a2, 0x8020
/* C8F818 80241C68 3C028024 */  lui       $v0, 0x8024
/* C8F81C 80241C6C 24423BB8 */  addiu     $v0, $v0, 0x3bb8
/* C8F820 80241C70 00041840 */  sll       $v1, $a0, 1
/* C8F824 80241C74 00641821 */  addu      $v1, $v1, $a0
/* C8F828 80241C78 00032080 */  sll       $a0, $v1, 2
/* C8F82C 80241C7C 00822021 */  addu      $a0, $a0, $v0
/* C8F830 80241C80 24630001 */  addiu     $v1, $v1, 1
/* C8F834 80241C84 00031880 */  sll       $v1, $v1, 2
/* C8F838 80241C88 00621821 */  addu      $v1, $v1, $v0
/* C8F83C 80241C8C 8C840000 */  lw        $a0, ($a0)
/* C8F840 80241C90 8C650000 */  lw        $a1, ($v1)
/* C8F844 80241C94 08090741 */  j         .L80241D04
/* C8F848 80241C98 34C64000 */   ori      $a2, $a2, 0x4000
.L80241C9C:
/* C8F84C 80241C9C 3C068020 */  lui       $a2, 0x8020
/* C8F850 80241CA0 3C028024 */  lui       $v0, 0x8024
/* C8F854 80241CA4 24423BB8 */  addiu     $v0, $v0, 0x3bb8
/* C8F858 80241CA8 00041840 */  sll       $v1, $a0, 1
/* C8F85C 80241CAC 00641821 */  addu      $v1, $v1, $a0
/* C8F860 80241CB0 00032080 */  sll       $a0, $v1, 2
/* C8F864 80241CB4 00822021 */  addu      $a0, $a0, $v0
/* C8F868 80241CB8 24630001 */  addiu     $v1, $v1, 1
/* C8F86C 80241CBC 00031880 */  sll       $v1, $v1, 2
/* C8F870 80241CC0 00621821 */  addu      $v1, $v1, $v0
/* C8F874 80241CC4 8C840000 */  lw        $a0, ($a0)
/* C8F878 80241CC8 8C650000 */  lw        $a1, ($v1)
/* C8F87C 80241CCC 08090741 */  j         .L80241D04
/* C8F880 80241CD0 34C67000 */   ori      $a2, $a2, 0x7000
.L80241CD4:
/* C8F884 80241CD4 3C028024 */  lui       $v0, 0x8024
/* C8F888 80241CD8 24423BB8 */  addiu     $v0, $v0, 0x3bb8
/* C8F88C 80241CDC 00041840 */  sll       $v1, $a0, 1
/* C8F890 80241CE0 00641821 */  addu      $v1, $v1, $a0
/* C8F894 80241CE4 00032080 */  sll       $a0, $v1, 2
/* C8F898 80241CE8 00822021 */  addu      $a0, $a0, $v0
/* C8F89C 80241CEC 24630001 */  addiu     $v1, $v1, 1
/* C8F8A0 80241CF0 00031880 */  sll       $v1, $v1, 2
/* C8F8A4 80241CF4 00621821 */  addu      $v1, $v1, $v0
/* C8F8A8 80241CF8 8C840000 */  lw        $a0, ($a0)
/* C8F8AC 80241CFC 8C650000 */  lw        $a1, ($v1)
/* C8F8B0 80241D00 34C6A000 */  ori       $a2, $a2, 0xa000
.L80241D04:
/* C8F8B4 80241D04 0C00A5CF */  jal       dma_copy
/* C8F8B8 80241D08 00000000 */   nop      
.L80241D0C:
/* C8F8BC 80241D0C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C8F8C0 80241D10 8FB10014 */  lw        $s1, 0x14($sp)
/* C8F8C4 80241D14 8FB00010 */  lw        $s0, 0x10($sp)
/* C8F8C8 80241D18 24020002 */  addiu     $v0, $zero, 2
/* C8F8CC 80241D1C 03E00008 */  jr        $ra
/* C8F8D0 80241D20 27BD0020 */   addiu    $sp, $sp, 0x20
/* C8F8D4 80241D24 00000000 */  nop       
/* C8F8D8 80241D28 00000000 */  nop       
/* C8F8DC 80241D2C 00000000 */  nop       
