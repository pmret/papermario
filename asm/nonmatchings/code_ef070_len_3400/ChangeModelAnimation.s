.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ChangeModelAnimation
/* F191C 802CCF6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F1920 802CCF70 AFB10014 */  sw        $s1, 0x14($sp)
/* F1924 802CCF74 0080882D */  daddu     $s1, $a0, $zero
/* F1928 802CCF78 AFBF0018 */  sw        $ra, 0x18($sp)
/* F192C 802CCF7C AFB00010 */  sw        $s0, 0x10($sp)
/* F1930 802CCF80 8E30000C */  lw        $s0, 0xc($s1)
/* F1934 802CCF84 8E050000 */  lw        $a1, ($s0)
/* F1938 802CCF88 0C0B1EAF */  jal       get_variable
/* F193C 802CCF8C 26100004 */   addiu    $s0, $s0, 4
/* F1940 802CCF90 0220202D */  daddu     $a0, $s1, $zero
/* F1944 802CCF94 8E050000 */  lw        $a1, ($s0)
/* F1948 802CCF98 0C0B1EAF */  jal       get_variable
/* F194C 802CCF9C 0040802D */   daddu    $s0, $v0, $zero
/* F1950 802CCFA0 3C03802E */  lui       $v1, %hi(gMeshAnimationsPtr)
/* F1954 802CCFA4 8C63AE30 */  lw        $v1, %lo(gMeshAnimationsPtr)($v1)
/* F1958 802CCFA8 00108080 */  sll       $s0, $s0, 2
/* F195C 802CCFAC 02038021 */  addu      $s0, $s0, $v1
/* F1960 802CCFB0 8E100000 */  lw        $s0, ($s0)
/* F1964 802CCFB4 8E030068 */  lw        $v1, 0x68($s0)
/* F1968 802CCFB8 10620004 */  beq       $v1, $v0, .L802CCFCC
/* F196C 802CCFBC 0040282D */   daddu    $a1, $v0, $zero
/* F1970 802CCFC0 8E040000 */  lw        $a0, ($s0)
/* F1974 802CCFC4 0C048052 */  jal       play_model_animation
/* F1978 802CCFC8 AE050068 */   sw       $a1, 0x68($s0)
.L802CCFCC:
/* F197C 802CCFCC 24020002 */  addiu     $v0, $zero, 2
/* F1980 802CCFD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* F1984 802CCFD4 8FB10014 */  lw        $s1, 0x14($sp)
/* F1988 802CCFD8 8FB00010 */  lw        $s0, 0x10($sp)
/* F198C 802CCFDC 03E00008 */  jr        $ra
/* F1990 802CCFE0 27BD0020 */   addiu    $sp, $sp, 0x20
